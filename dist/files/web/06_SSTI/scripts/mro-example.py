#! python3

import sys

class A(object):
    def func(self):
        sys.stdout.write('A')
        sys.stdout.write('\n')
        
class B(A):
    def func(self):
        sys.stdout.write('B')
        super().func()

class C(A):
    def func(self):
        sys.stdout.write('C')
        super().func()

        
class D(B, C):
    def func(self):
        sys.stdout.write('D')
        super().func()


print('MRO of A is...')
print(A.mro())
print('MRO of B is...')
print(B.mro())
print('MRO of C is...')
print(C.mro())
print('MRO of D is...')
print(D.mro())
        
A().func()
B().func()
C().func()
D().func()

