#! python3

s = 'test'
print(s.__class__)
print(s.__class__.mro())
print(s.__class__.mro()[-1])

