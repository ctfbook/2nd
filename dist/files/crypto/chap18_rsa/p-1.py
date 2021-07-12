from Crypto.Util.number import *

def next_prime(x):
    while True:
        x += 1
        if isPrime(x):
            return x

x = 2**8 * 3**5 * 5**4 * 7**3
x *= 11 * 13 * 17 * 19 * 23 * 29 * 31 * 37
x *= getPrime(10)
while True:
    p = x * getPrime(16) + 1
    if isPrime(p):
        break

q = getPrime(p.bit_length())
N = p * q
print('N:', N)

B = 65537
pp = 1
M = 1
print('Generating M...')
while True:
    pp = next_prime(pp)
    if pp > B:
        break
    M *= pp * int(math.log(B, pp))
print('Bits of M:', M.bit_length())

print('Find prime')
for a in range(2, 1000):
    g = GCD(pow(a, M, N) - 1, N)
    if g > 1:
        print('p:', g)
        print('q:', N//g)
        break
