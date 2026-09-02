img=imread('temple.jpg');
E=rgb2ycbcr(img);
disp(size(E));
E(:,:,1)=E(:,:,1)-50;
fin=ycbcr2rgb(E);
imshow(fin)