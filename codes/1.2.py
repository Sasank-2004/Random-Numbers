import numpy as np
import matplotlib.pyplot as plt
import scipy

def F(x):
	if (x<0) : return 0
	elif (x<1) : return x
	else : return 1
x = np.linspace(-4,4,30)
simlen = int(1e6)
err = [] 
randvar = np.loadtxt('uni.dat',dtype='double')
for i in range(0,30):
	err_ind = np.nonzero(randvar < x[i]) 
	err_n = np.size(err_ind) 
	err.append(err_n/simlen) 
	y.append(F(x[i]))

vec_y = scipy.vectorize(F,otypes=[float])
plt.plot(x.T,err)
plt.plot(x,vec_y(x),'o')
plt.legend(["Numerical","Theory"])
plt.grid() 
plt.xlabel('$x$')
plt.ylabel('$F_X(x)$')
plt.show()
