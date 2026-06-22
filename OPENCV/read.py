import cv2

img = cv2.imread("asset/temple.jpg")

cv2.imshow('Original', img)

cv2.waitKey(0)
cv2.destroyAllWindows()