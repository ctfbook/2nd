from Crypto.Cipher import ARC4
cipher = ARC4.new(b'secretkey')
encrypted = cipher.encrypt(b'{"username": "user1"}')
bitflip = bytearray(encrypted)
bitflip[14] ^= ord('u') ^ ord('a')
bitflip[15] ^= ord('s') ^ ord('d')
bitflip[16] ^= ord('e') ^ ord('m')
bitflip[17] ^= ord('r') ^ ord('i')
bitflip[18] ^= ord('1') ^ ord('n')

# RC4を初期状態に戻す
cipher = ARC4.new(b'secretkey')
print(cipher.decrypt(bitflip))

