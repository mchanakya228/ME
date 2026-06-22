img=imread('temple.jpg');
a=size(img)
w=rgb2ycbcr(img);
for i=1:a(1)
    for j=1:a(2)
        w(i,j,1)=w(i,j,1)-50;
    end
end
disp('The Y channel has been decreased by 50 for all pixels.')
q=ycbcr2rgb(w);
imshow(q)  