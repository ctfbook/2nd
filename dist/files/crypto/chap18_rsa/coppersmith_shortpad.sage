# RSA パラメータ
bits = 128
p = random_prime(2^bits)
q = random_prime(2^bits)
N = p * q
e = 3

# 問題生成
m = ZZ.random_element(N)
diff_size = floor(N.nbits() / (e^2) / 2)
diff = ZZ.random_element(2^diff_size)
c1 = pow(m, e, N)
c2 = pow(m + diff, e, N)
print('c1:', hex(c1))
print('c2:', hex(c2))

# Coppersmith法による差の計算
PR.<x,y> = PolynomialRing(Zmod(N))
PRS.<xs> = PolynomialRing(Zmod(N))
f = x^e - c1
g = (x+y)^e - c2

ff = f.change_ring(PRS)
gg = g.change_ring(PRS)
r = gg.resultant(ff) # 終結式
r = r.univariate_polynomial().subs(y=xs).monic()

diff_ans = r.small_roots(epsilon=1/50)
if len(diff_ans) > 0:
    print('Diff:', diff_ans[0])
else:
    print('Failed')
print('Answer:', diff)

# Example Output
# c1: 0x78097c6474fe9c04adb4d03c7a19dad278730fae49ba5cffb1d513e30a679975
# c2: 0x1187b9c2065d1f99def846117ad33510908cb8e5d34aeeae921ea8f54ffc5f02
# Diff: 12394
# Answer: 12394
