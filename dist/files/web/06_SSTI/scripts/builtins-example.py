#! python3

class A(object):
    def func():
        pass

print(A.func.__globals__)
i = A.func.__globals__['__builtins__']
i.print("hello from __builtins__ from __globals__ from func")

