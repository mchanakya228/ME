import cv2
import numpy as np
img=cv2.imread('asset/temple.jpg')
q=cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
height,width,channels=q.shape
for i in range(1,height+1):
    for j in range (1,width+1):
         q[8*i:8*j:0]
         q[8*i:8*j:1]
         q[8*i:8*j:2]