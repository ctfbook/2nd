import socket
from binascii import hexlify, unhexlify

def recvuntil(s, delim=b'\n'):
    buf = b''
    while delim not in buf:
        buf += s.recv(1)
    return buf

def attack_block(block, prev, oracle_func):
    attack = bytearray(b'\x00' * 16)
    plaintext = bytearray(b'\x00' * 16)
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

        # パディング値, 攻撃用ブロック, 1ブロック前の暗号文をXOR
        plaintext[15-i] = (i + 1) ^ attack[15-i] ^ prev[15-i]

    return plaintext

def oracle(sock):
    def _oracle(data):
        sock.send(hexlify(data) + b'\n')
        buf = recvuntil(sock).strip()
        return b'True' in buf
    return _oracle

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(('localhost', 4444))

encrypted = unhexlify(recvuntil(sock).strip())
result = b''

for i in range(16, len(encrypted), 16):
    prev = encrypted[i-16:i]
    block = encrypted[i:i+16]
    result += attack_block(block, prev, oracle(sock))

print(result)
