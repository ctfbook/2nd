flist = [6, 9, 7, 11, 5, 1, 5, 5, 2, 14, 3, 3, 0, 0, 1, 7, 14, 4, 15, 11]

def func(i):
    return (flist[i*2]^i)*16 + (flist[i*2+1]^(i+1))

password = ''
for i in range(10):
    password += chr(func(i))

print(password)
