import random

# y = x ^ ((x << shift) & mask) を戻す
def left_unshift(x, shift, mask):
    i = shift
    y = x
    while i < 32:
        y = x ^ ((y << shift) & mask)
        i += shift
    return y

# y = x ^ (x >> shift) を戻す
def right_unshift(x, shift):
    i = shift
    y = x
    while i < 32:
        y = x ^ (y >> shift)
        i += shift
    return y

rnd = random.Random()
numbers = [rnd.getrandbits(32) for i in range(624)]

for i in range(len(numbers)):
    num = numbers[i]
    num = right_unshift(num, 18)
    num = left_unshift(num, 15, 0xefc60000)
    num = left_unshift(num, 7, 0x9d2c5680)
    num = right_unshift(num, 11)
    numbers[i] = num

state = rnd.getstate()[1][:-1]
print('Check:', numbers == list(state))
