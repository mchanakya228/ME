import numpy as np
import matplotlib.pyplot as plt

lam=100
exposure=[0.1,0.01,1,0.23]


for i in exposure:
    lamd=lam*i
    noise=np.random.poisson(lamd,100000)
    print(f"Exposure ={i}s | "
          f"Mean = {np.mean(noise): .2f} |"
          f" Std={np.std(noise):.2f}")
    