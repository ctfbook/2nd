def safe_prime(n):
    while True:
        q = random_prime(n)
        p = 2 * q + 1
        if p.is_prime():
            return p

p = safe_prime(2^128)
g = 3
x = 12345678
y = pow(g, x, p)

a = 123
b = 4567

r = ZZ(pow(g, a, p) * pow(y, b, p) % p)
s = -r * pow(b, -1, p-1) % (p-1)
m = -r * a * pow(b, -1, p-1) % (p-1)

print('p:', p)
print('r:', r)
print('s:', s)
print('m:', m)
print()
print('g^m     :', pow(g, m, p))
print('validate:', pow(y, r, p) * pow(r, s, p) % p)
