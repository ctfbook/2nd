from sage.groups.generic import bsgs

# 鍵生成
p = 27986912805633997850732479367
g = 5
x = ZZ.random_element(p-1)
h = pow(g, x, p)
print('p:', p)
print('p_len:', p.nbits())
print('x:', x)
print('h:', h)

# Pohlig-Hellman
pm1 = p-1
factors = pm1.factor()
print('factors:', factors)

print('subgroup solution:')
xs = []
mods = []
for num, i in factors:
    suborder = num^i
    sub_h = pow(h, pm1/suborder, p)
    sub_g = pow(g, pm1/suborder, p)
    sub_x = bsgs(sub_g, sub_h, (0, p-1))
    print('x = {} mod {}'.format(sub_x, suborder))

    mods.append(suborder)
    xs.append(sub_x)

x2 = crt(xs, mods)
print('real x: ', x)
print('calculated x:', x2)
