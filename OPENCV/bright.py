import cv2

img = cv2.imread("asset/temple.jpg")

q=cv2.cvtColor(img,cv2.COLOR_BGR2YCrCb)
height,width,channels=q.shape
for i in range(height):
    for j in range(width):
        y=int(q[i,j,0])
        y-=50
        if y<0:
            y=0
        q[i,j,0]=y
        
e=cv2.cvtColor(q,cv2.COLOR_YCrCb2BGR)
cv2.imshow('bright',e)

cv2.waitKey(0)
cv2.destroyAllWindows()