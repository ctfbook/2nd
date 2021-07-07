from z3 import *

s = Solver()
n = BitVec("code", 32) # 32-bitのビット列とする

# 普通の変数のように扱える
a = n & 0xff
b = (n >> 8) & 0xff
c = (n >> 16) & 0xff
d = (n >> 24) & 0xff

# 制約を追加
s.add(And( # ブール式の積はAndを使う
    a + b + c + d == 824,
    a - b + c - d == 0,
    a * b + c * d == 83816,
    a * b - c * d == 7004
))

r = s.check()
if r == sat:
    # 解が見つかった
    m = s.model()
else:
    # 解が存在しない
    print("[-] Solution not found")
    exit(1)

answer = m[n].as_long()
print("[+] CODE: {0} (0x{0:x})".format(answer))
