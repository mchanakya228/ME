img=imread('temple.jpg');



A=double(img(:,:,1));
B=double(img(:,:,2));
C=double(img(:,:,3));

[U,S,V]=svd(A);
[L,M,N]=svd(B);
[X,Y,Z]=svd(C);
k=50; % Number of singular values to keep
% Reconstruct the image using the top k singular values
D=U(:,1:k)*S(1:k,1:k)*V(:,1:k)';
G=L(:,1:k)*M(1:k,1:k)*N(:,1:k)';
H=X(:,1:k)*Y(1:k,1:k)*Z(:,1:k)';

img2(:,:,1) = uint8(D);   % Red
img2(:,:,2) = uint8(G);   % Green
img2(:,:,3) = uint8(H);   % Blue

imshow(img2)
title('Compressed Color Image')