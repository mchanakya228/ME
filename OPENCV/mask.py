import cv2 as cv
img=cv.imread("asset/temple.jpg")
gray =cv.cvtColor(img,cv.COLOR_BGR2GRAY)
_,mask= cv.threshold(gray,127,255,cv.THRESH_BINARY)
result=cv.bitwise_and(img,img,mask=mask)
cv.imshow("result",result)
cv.waitKey(0)
cv.destroyAllWindows