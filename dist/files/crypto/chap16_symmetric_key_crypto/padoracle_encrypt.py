import socket
from binascii import hexlify, unhexlify

def pad(x):
    return x + bytes([16 - len(x) % 16] * (16 - len(x) % 16))

def recvuntil(s, delim=b'\n'):
    buf = b''
    while delim not in buf:
        buf += s.recv(1)
    return buf

def attack_block(block, plaintext, oracle_func):
    attack = bytearray(b'\x00' * 16)
    prev = bytearray(b'\x00' * 16)
    for i in range(16):
        # 末尾iバイトのパディングを調整
        for j in range(i):
            attack[15-j] ^= i ^ (i + 1)

        # 256通りの総当り
        for j in range(256):
            attack[15-i] = j
            if oracle_func(bytes(attack) + block):
                break
        else:
            # 256通りすべてでTrueが出力されなかった
            return False

        # パディング値, 攻撃用ブロック, 目的の平文をXOR
        prev[15-i] = (i + 1) ^ attack[15-i] ^ plaintext[15-i]

    return prev

def oracle(sock):
    def _oracle(data):
        sock.send(hexlify(data) + b'\n')
        buf = recvuntil(sock).strip()
        return b'True' in buf
    return _oracle

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(('localhost', 4444))
encrypted = unhexlify(recvuntil(sock).strip())  # 使わない

# 暗号化する文章
plaintext = pad(b'Encryption_By_PaddingOracleAttack!!')

# 改ざんされる前の暗号文: 任意の値を使える
result = b'A' * 16

for i in range(len(plaintext), 0, -16):
    pt = plaintext[i-16:i]
    block = result[:16]
    print(i, pt, block)
    result = attack_block(block, pt, oracle(sock)) + result

sock.send(hexlify(result) + b'\n')
print('Encrypted:', result)
