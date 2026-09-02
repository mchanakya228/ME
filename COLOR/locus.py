import numpy as np
import matplotlib.pyplot as plt

# Analytic multi-lobe Gaussian approximation to CIE 1931 2-degree CMFs
# Wyman, Sloan, Shirley - "Simple Analytic Approximations to the CIE XYZ
# Color Matching Functions" (JCGT 2013). Good to a few % - fine for
# illustrating the spectral locus shape and computation method.

def g(x, mu, sigma1, sigma2):
    sigma = np.where(x < mu, sigma1, sigma2)
    return np.exp(-0.5 * ((x - mu) / sigma) ** 2)

def xbar(w):
    return (1.056 * g(w, 599.8, 37.9, 31.0)
            + 0.362 * g(w, 442.0, 16.0, 26.7)
            - 0.065 * g(w, 501.1, 20.4, 26.2))

def ybar(w):
    return (0.821 * g(w, 568.8, 46.9, 40.5)
            + 0.286 * g(w, 530.9, 16.3, 31.1))

def zbar(w):
    return (1.217 * g(w, 437.0, 11.8, 36.0)
            + 0.681 * g(w, 459.0, 26.0, 13.8))

wavelengths = np.arange(380, 701, 1.0)
X = xbar(wavelengths)
Y = ybar(wavelengths)
Z = zbar(wavelengths)

S = X + Y + Z
x = X / S
y = Y / S

# print a sample table every 20nm
print(f"{'nm':>5} {'X':>8} {'Y':>8} {'Z':>8} {'x':>8} {'y':>8}")
for wl in range(380, 701, 20):
    i = np.argmin(np.abs(wavelengths - wl))
    print(f"{wavelengths[i]:5.0f} {X[i]:8.4f} {Y[i]:8.4f} {Z[i]:8.4f} {x[i]:8.4f} {y[i]:8.4f}")

# --- Plot ---
fig, ax = plt.subplots(figsize=(7,7))

# close the locus with the line of purples
x_closed = np.append(x, x[0])
y_closed = np.append(y, y[0])
ax.plot(x_closed, y_closed, '-', color='black', linewidth=1.5)

# mark every 20nm with a label
for wl in range(380, 701, 20):
    i = np.argmin(np.abs(wavelengths - wl))
    ax.plot(x[i], y[i], 'o', color='dimgray', markersize=3)
    ax.annotate(f'{wl}', (x[i], y[i]), textcoords="offset points",
                xytext=(6,2), fontsize=7, color='dimgray')

# D65 white point for reference
xw, yw = 0.3127, 0.3290
ax.plot(xw, yw, '+', color='red', markersize=10, markeredgewidth=2)
ax.annotate('D65', (xw, yw), textcoords="offset points", xytext=(6,-10), fontsize=8, color='red')

ax.set_xlim(-0.05, 0.85)
ax.set_ylim(-0.05, 0.9)
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_title('CIE 1931 Chromaticity Diagram — Spectral Locus\n(analytic CMF approximation)')
ax.set_aspect('equal')
ax.grid(alpha=0.3)

plt.tight_layout()
plt.show()