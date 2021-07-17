def xorshift128(x, y, z, w):
    mask = 0xffffffff
    while True:
        t = (x ^ (x << 11)) & mask
        x, y, z = y, z, w
        w = ((w ^ (w >> 19)) ^ (t ^ (t >> 8))) & mask
        yield w

gen = xorshift128(123456789, 362436069, 521288629, 88675123)

for i in range(10):
    print(next(gen))

# 実行結果
# 3701687786
# 458299110
# 2500872618
# 3633119408
# 516391518
# 2377269574
# 2599949379
# 717229868
# 137866584
# 395339113
