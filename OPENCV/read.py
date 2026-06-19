import cv2

img = cv2.imread("asset/temple.jpg")
YCrCb=cv2.cvtColor(img,cv2.COLOR_BGR2YCrCb)
cv2.imshow("Y",YCrCb[:,:,2])
cv2.waitKey(0)
cv2.destroyAllWindows()