from hashlib import sha1
import string

prefix = 'CTF_'
chars = string.ascii_letters + string.digits

found = False
for c1 in chars:
    for c2 in chars:
        _input = prefix + c1 + c2
        shahash = sha1(_input.encode()).hexdigest()
        if shahash[-3:] == '000':
            print(_input, shahash)
            found = True
            break
    if found:
        break
