import numpy as np
import matplotlib.pyplot as plt
data = np.loadtxt("lab2.txt")
plt.plot(data[:, 0], data[:, 1])
plt.plot([1818,
1819,
1820,
1821,
1822,
1823,
1824,
1825,
1826,
1827,
1828,
1829],[12,
13.6,
13.4,
12.8,
13.9,
14.4,
11.8,
15.1,
15.7,
14.5,
15.1,
13],'ro')
plt.show()
