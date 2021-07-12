from hashlib import sha1
from binascii import hexlify

BLOCK_SIZE = 64 # ハッシュ関数のブロックサイズ
ipad = b'\x36' * BLOCK_SIZE
opad = b'\x5c' * BLOCK_SIZE

def xor(s1, s2):
  return bytes([ a ^ b for a, b in zip(s1, s2) ])

def hmac_sha1(key, msg):
  if len(key) > BLOCK_SIZE:
    key = sha1(key).digest()

  key = key + b'\x00' * (BLOCK_SIZE - len(key))

  k_opad = xor(key, opad)
  k_ipad = xor(key, ipad)
  return sha1(k_opad + sha1(k_ipad + msg).digest())

print(hmac_sha1(b'secretkey', b'somedata').hexdigest())
# => b9a7a9d5256a599d69f09586278e046ce6430254
