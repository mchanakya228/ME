import matplotlib.pyplot as plt
import numpy as np
plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.title("Sample Plot")
x = np.linspace(0,5,6)
y=-(x-3)**2+10
plt.plot(x, y)
plt.show()