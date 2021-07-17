from Crypto.Cipher import AES
from binascii import hexlify, unhexlify
import sys
import logging

logger = logging.getLogger('PadOracle')
logger.addHandler(logging.StreamHandler())
logger.setLevel(10)

def pad(x):
    return x + bytes([16 - len(x) % 16] * (16 - len(x) % 16))

def unpad(x):
    ch = x[-1]
    if ch < 1 or ch > 16 or len(x) % 16 != 0:
        return False
    for i in range(len(x) - ch, len(x)):
        if x[i] != ch:
            return False
    return x[:len(x)-ch]

key = b'samplekey0123456'
data = pad(b'BLOCK01_abcdefg_BLOCK02_abcdefg_BLOCK03')
iv = open('/dev/urandom', 'rb').read(16)
cipher = AES.new(key, AES.MODE_CBC, iv)
print(hexlify(iv + cipher.encrypt(data)).decode())

while True:
    data = unhexlify(input('Decrypt> '))
    cipher = AES.new(key, AES.MODE_CBC, data[:16])
    dec = cipher.decrypt(data[16:])
    print(unpad(dec) != False)
    logger.debug('DEBUG: {}'.format(unpad(dec)))
