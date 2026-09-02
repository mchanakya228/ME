import cv2 as cv
import numpy as np
img=cv.imread('temple.jpg')
gray=cv.cvtColor(img,cv.COLOR_BGR2GRAY)
A=np.array(gray)
A

