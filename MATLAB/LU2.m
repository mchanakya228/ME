a=input('Enter the value of a: ');
b=input('Enter the value of b: ');  
c=input('Enter the value of c: ');
d=input('Enter the value of d: ');
A=[a b;c d];
if a==0
    disp('row exchange is needed')

else
    m=c/a;    
    L=[1 0;m 1];
end
disp('The L matrix is:')
disp(L)
%if no row exchnages multipliers directly give the L matrix
