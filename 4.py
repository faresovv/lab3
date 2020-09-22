import numpy as np
import matplotlib.pyplot as plt
data = np.loadtxt("laba4.txt")
plt.plot(data[:, 0], data[:, 1])
plt.plot([0,1,2,3,4,5],[10.8,
8.5,
8.4,
13.7,
8.9,
12.7
],'ro')
plt.show()
