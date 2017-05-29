import matplotlib.pyplot as plt
import math
import numpy as np
import matplotlib.animation as animation

def step(x,vx,dt):
    return x + (vx*dt)

def vstep(x,y,vx,dt):
    return vx - ((4*(math.pi**2)*x*dt)/math.pow(x**2 + y**2,3/2.0))

N = 100000
dt = 0.002
x = [1]
y = [0]
vx = [0]
vy = [2.8*math.pi]

for i in range (1,N):
    vx.append(vstep(x[i-1],y[i-1],vx[i-1],dt))
    vy.append(vstep(y[i-1],x[i-1],vy[i-1],dt))
    x.append(step(x[i-1],vx[i],dt))
    y.append(step(y[i-1],vy[i],dt))

fig = plt.figure()
ax = fig.add_subplot(111)
ax.set_aspect('equal')
ax.set_xlim([np.amin(x),np.amax(x)])
ax.set_ylim([np.amin(y),np.amax(y)])
plt.plot(x,y)
plt.show()
