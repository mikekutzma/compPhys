import numpy as np
import matplotlib.pyplot as plt

x = np.arange(5)
y = np.arange(6)
z = x*y[:,np.newaxis]

for i in range(5):
    if i==0:
        p = plt.imshow(z)
        fig = plt.gcf()
        plt.clim()
    else:
        z = z+2
        p.set_data(z)
    plt.pause(0.5)
