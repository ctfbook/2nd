import hashlib
import sys
import random
from binascii import hexlify, unhexlify
# 紙面の都合でソルトを直接定義しています
# 本来はユーザからは見えません
SALT = b'secretsalt'
# --------------------------------------------------
print('[Register]')
username = input('username> ').encode()
if b'=' in username:
    print('Bye.')
    sys.exit(1)

userdata = b'priv=guest,username=' + username
h = hashlib.md5(SALT + userdata).hexdigest()
print('Your userdata(hex) is:', hexlify(userdata).decode())
print('Your signature is:', h)
# --------------------------------------------------
print('[Login]')
userdata = unhexlify(input('userdata(hex)> '))
sig = input('signature(hex)> ')
h = hashlib.md5(SALT + userdata).hexdigest()
if h == sig:
    print('Login OK!')

    if b'priv=admin' in userdata.split(b','):
        print('Congratulations! You are admin!')
    else:
        print('Sorry, admin only')
else:
    print('Bye.')
    sys.exit(1)

