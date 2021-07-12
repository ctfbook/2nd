# ax + by = 1 を満たす (x, y) を返す
def exgcd(a, b):
    if a == 0:
        return (0, 1 // b)

    q = b // a
    r = b % a
    s, t = exgcd(r, a)
    return (t - q * s, s)

print(exgcd(5, 3))
# (-1, 2)
