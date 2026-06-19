img=imread('temple.jpg');
ycbcr=rgb2ycbcr(img);
imshow(ycbcr(:,:,2));
disp(size(img));


