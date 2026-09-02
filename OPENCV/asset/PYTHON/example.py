import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

img=cv.imread("temple.jpg",cv.IMREAD_GRAYSCALE)
img_fine=img.astype(np.float32)/255

max=1000
expected=img_fine*max
photons=np.random.poisson(expected)
noisy=photons/max*255
noisy=np.clip(noisy,0,255).astype(np.uint8)
plt.figure(figsize=(10,5))

plt.subplot(1,2,1)
plt.imshow(img, cmap="gray")
plt.title("Original")
plt.axis("off")

plt.subplot(1,2,2)
plt.imshow(noisy, cmap="gray")
plt.title("Poisson Shot Noise")
plt.axis("off")

plt.show()