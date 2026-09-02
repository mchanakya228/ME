import numpy as np 
import matplotlib.pyplot as plt

lam=100
samples=np.random.poisson(lam,100000)

print("Mean: ",np.mean(samples))
print("Variance: ",np.var(samples))
print("Mean: ",lam)
print("var: ",lam)

plt.hist(samples,bins=30,density=True)
plt.xlabel("Detected photons")
plt.xlabel("p")
plt.title("Photon shot noise")
plt.show()

