import numpy as np
a=int(input('Enter the value of a: '))
b=int(input('Enter the value of b: '))
c=int(input('Enter the value of c: '))
d=int(input('Enter the value of d: '))
A=np.array([[a,b],[c,d]])
if a==0:
    print('row exchange is needed')
else:
    m=c/a
    L=np.array([[1, 0], [m, 1]])
    print('The L matrix is:')
    print(L) 