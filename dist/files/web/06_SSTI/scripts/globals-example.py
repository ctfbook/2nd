#! python3

def func():
    pass

class A:

    @classmethod
    def method(cls):
        pass

    def func(self):
        pass

    def _func(self):
        self.A  = 'a'


print('===function: func===')
print(hasattr(func, '__globals__'))

print('===function: A.func===')
print(hasattr(A.func, '__globals__'))

print('===method: A.method===')
print(hasattr(A.method, '__globals__'))

