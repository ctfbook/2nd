# RSA Parameters
bits = 256
p = random_prime(2^bits)
q = random_prime(2^bits)
if p < q:
    p, q = q, p
n = p * q

mask = (1 << p.nbits()) - (1 << int(p.nbits()/3))
p_high = p & mask
print('p\t', hex(p))
print('p_high\t', hex(p_high))

PR.<x> = PolynomialRing(Zmod(n))
f = p_high + x
diff = f.small_roots(beta=0.5)
if len(diff):
    print('result\t', hex(p_high + diff[0]))

