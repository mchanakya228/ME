clc
clear
close all

img = imread('temple.jpg');

gray = rgb2gray(img);

F = fft2(gray);

Fc = fftshift(F);

figure

subplot(1,2,1)
imshow(gray)
title('Original Image')

subplot(1,2,2)
imshow(log(1+abs(Fc)),[])
colormap gray
colorbar
title('FFT Magnitude Spectrum')