import cv2 as cv
import numpy as np
img = cv.imread('asset/temple.jpg')
q=cv.cvtColor(img,cv.COLOR_BGR2RGB)
height,width,channels=q.shape
crop=img[0:height-250,0:width-1000,:]
cv.imshow("img",crop)
cv.waitKey(0)
cv.destroyAllWindows()
