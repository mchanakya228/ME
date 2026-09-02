x=[-20:20];
for i =1:1:41
    if x(i)>=0
        y(i)=1;
    else 
        y(i)=0;
    stem(x,y)
    end
end
