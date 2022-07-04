import numpy as np
import matplotlib.pyplot as plt
import math

def F(x):
	if (x<0) : return 0
	else : return 1-math.exp(-x/2)
x = np.linspace(-4,4,30)
simlen = int(1e6)
err = [] 
y = []
randvar = np.loadtxt('var.dat',dtype='double')
for i in range(0,30):
	err_ind = np.nonzero(randvar < x[i]) 
	err_n = np.size(err_ind) 
	err.append(err_n/simlen) 
	y.append(F(x[i]))
	
plt.plot(x.T,err)
plt.plot(x,y,'o')
plt.legend(["Numerical","Theory"])
plt.grid() 
plt.xlabel('$x$')
plt.ylabel('$F_V(x)$')
plt.show()
