import math

S = ([7, 12, 17, 22] * 4 +
     [5,  9, 14, 20] * 4 +
     [4, 11, 16, 23] * 4 +
     [6, 10, 15, 21] * 4)

K = [ int((1<<32) * abs(math.sin(i))) for i in range(1, 65) ]
Fs = [
        lambda B, C, D: (B & C) | (~B & D),
        lambda B, C, D: (B & D) | (C & ~D),
        lambda B, C, D: B ^ C ^ D,
        lambda B, C, D: C ^ (B | ~D)
]

# 32bit 左ローテート
def rol(n, shift):
    return ((n << shift) | (n >> (32 - shift))) & 0xffffffff

# ブロックサイズになるようにパディング
def md5_pad(msg, offset=0):
    msg_len = len(msg) + offset
    msg += b'\x80'
    if (len(msg) + offset) % 64 > 56:
        msg += b'\x00' * ((64 - (len(msg) + offset) % 64) + 56)
    else:
        msg += b'\x00' * (56 - (len(msg) + offset) % 64)

    msg += (msg_len << 3).to_bytes(8, byteorder='little')
    return msg

def md5(msg, IV=(0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476), offset=0):
    A0, B0, C0, D0 = IV
    msg = md5_pad(msg, offset)

    gs = [(1, 0), (5, 1), (3, 5), (7, 0)]
    for i in range(len(msg) // 64):
        block = msg[i*64:(i+1)*64]
        A, B, C, D = A0, B0, C0, D0

        for j in range(64):
            jj = j // 16
            F = Fs[jj](B, C, D)
            g = (gs[jj][0] * j + gs[jj][1]) % 16

            word = int.from_bytes(block[g*4:g*4+4], 'little')
            F = (Fs[jj](B, C, D) + A + K[j] + word) & 0xffffffff
            A = D
            D = C
            C = B
            B = B + rol(F, S[j])

        A0 = (A0 + A) & 0xffffffff
        B0 = (B0 + B) & 0xffffffff
        C0 = (C0 + C) & 0xffffffff
        D0 = (D0 + D) & 0xffffffff

    return b''.join(map(lambda x: x.to_bytes(4, byteorder='little'), [A0, B0, C0, D0]))

if __name__ == '__main__':
    from binascii import hexlify, unhexlify
    data = input('data> ')
    h = unhexlify(input('hash> '))
    add_data = input('additional data> ').encode()
    prefix_len = int(input('prefix length> '))

    A = int.from_bytes(h[:4], 'little')
    B = int.from_bytes(h[4:8], 'little')
    C = int.from_bytes(h[8:12], 'little')
    D = int.from_bytes(h[12:16], 'little')

    padded_data = md5_pad(data.encode(), prefix_len)
    new_hash = md5(add_data, (A, B, C, D), len(padded_data) + prefix_len)
    print('data:', hexlify(padded_data + add_data).decode())
    print('hash:', hexlify(new_hash).decode())


