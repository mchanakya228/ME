import cv2 as cv
img = cv.imread('asset/temple.jpg', cv.IMREAD_COLOR)  # or correct path
if img is None:
    raise FileNotFoundError("Could not load image")

B, G, R = cv.split(img)
cv.imshow('Blue', B)
cv.imshow('Green', G)
cv.imshow('Red', R)
cv.waitKey(0)
cv.destroyAllWindows()