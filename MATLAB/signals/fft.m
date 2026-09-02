clc 
clear
close all
x=[1 2 3 4];
y=fft(x)
subplot(1,2,1)
stem(x-1,real(y))
subplot(1,2,2)
stem(x-1,imag(y))