import numpy as np
import matplotlib.pyplot as plt

f = 1

Z = np.arange(10, 1001)

x1 = -5 * f / Z
x2 =  5 * f / Z

length = np.abs(x2 - x1)

plt.plot(Z, length)
plt.xlabel("Distance Z")
plt.ylabel("Projected Length")
plt.title("Projected Length vs Distance")
plt.grid(True)
plt.show()