from functools import reduce
def CRT(a, m):
    MM = reduce(lambda a, b: a * b, m)
    x = 0
    for i in range(len(a)):
        Mi = MM // m[i]
        ti = pow(Mi, -1, m[i])
        x += (Mi * ti * a[i]) % MM
    return x % MM

print(CRT([2, 3, 2], [3, 5, 7]))
# 23
