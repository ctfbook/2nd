#! python3

class A(object):
    pass

class B(A):
    pass

class C(A):
    pass

class D(B, C):
    pass

print('subclasses of A are...')
print(A.__subclasses__())
print('subclasses of B are...')
print(B.__subclasses__())
print('subclasses of C are...')
print(C.__subclasses__())
print('subclasses of D are...')
print(D.__subclasses__())
        
