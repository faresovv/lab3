import numpy as np
import matplotlib.pyplot as plt
data = np.loadtxt("laba31.txt")
plt.plot(data[:, 0], data[:, 1])
plt.plot([1898,1899,1900,1901,1902,1903],[10.8,
8.5,
8.4,
13.7,
8.9,
12.7
],'ro')
plt.show()
