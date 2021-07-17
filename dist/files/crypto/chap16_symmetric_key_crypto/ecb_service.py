from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
from binascii import hexlify, unhexlify
import json

key = b'0123456789abcdef'
cipher = AES.new(key, AES.MODE_ECB)

while True:
    username = input('username> ')
    if username == 'exit':
        break

    plain = json.dumps({'username': username, 'admin': 0}).encode()
    encrypted = cipher.encrypt(pad(plain, AES.block_size))

    print(hexlify(encrypted).decode())

challenge = input('challenge> ')
challenge = unhexlify(challenge)
data = json.loads(unpad(cipher.decrypt(challenge), AES.block_size))
if data['admin'] == 1:
    print('OK! Flag is FLAG{sampleflag}')
else:
    print('You\'re not admin')
