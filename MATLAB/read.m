clc,clearvars,close all
x=linspace(-10,10,100);
y1=-(x-3).^2+10;
y2=y1+5;
y3=-(x-5).^2+10;
hold on
plot(x,y1,'ro')
xlabel('x-axis'),ylabel('y-axis')
title('y1=-(x-3).^2+10')
grid on 
hold on
plot(x,y2,'b+')

hold on
plot(x,y3,'ys')

legend('y1','y2','y3')