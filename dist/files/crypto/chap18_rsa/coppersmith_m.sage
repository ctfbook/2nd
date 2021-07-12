def int2bytes(n):
    L = n.bit_length()
    return n.to_bytes(floor((L+7)/8), 'big')

# RSA Parameters
bits = 512
p = random_prime(2^bits)
q = random_prime(2^bits)
N = p * q
e = 3
flag = b'FLAG{recovery_part_of_m}'
prefix = int.from_bytes(b'The flag is: ', 'big') << (len(flag)*8)
m = prefix + int.from_bytes(flag, 'big')
c = pow(m, e, N)

# Coppersmith's method
PR.<x> = PolynomialRing(Zmod(N))
f = (prefix + x)^e - c
diff = f.small_roots()
if len(diff):
    print(int2bytes(int(diff[0])))
else:
    print('not found')

# 実行結果
# b'FLAG{recovery_part_of_m}'
