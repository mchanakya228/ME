img=imread("temple.jpg")
gray=rgb2gray(img);
gray=im2double(gray);
mask=gray>125/255
result=img;
result(repmat(~mask,[1,1,3]))=0;
subplot(2,2,1)

imshow(result)
subplot(2,2,2)

imshow(gray)
subplot(2,2,3)

imshow(img)
