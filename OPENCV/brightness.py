import cv2 as cv
import numpy as np
img=cv.imread('asset/temple.jpg')
rgb=cv.cvtColor(img,cv.COLOR_BGR2YCrCb)
rows,columns,channels=rgb.shape
Y=rgb[:,:,0].astype(np.int16)
Y=np.clip(Y-50,0,255)
rgb[:,:,0]=Y.astype(np.uint8)
e=cv.cvtColor(rgb,cv.COLOR_YCrCb2BGR)
cv.imshow('sd',e)
cv.waitKey(0)
cv.destroyAllWindows

        