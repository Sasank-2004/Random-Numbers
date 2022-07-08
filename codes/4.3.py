import numpy as np
import mpmath as mp
import scipy 
import matplotlib.pyplot as plt

maxrange=50
maxlim=6.0
x = np.linspace(-maxlim,maxlim,maxrange)
simlen = int(1e6) 
err = [] 
pdf = []
h = 2*maxlim/(maxrange-1);
randvar = np.loadtxt('tri.dat',dtype='double')

for i in range(0,maxrange):
	err_ind = np.nonzero(randvar < x[i]) 
	err_n = np.size(err_ind)
	err.append(err_n/simlen) 
	
for i in range(0,maxrange-1):
	test = (err[i+1]-err[i])/(x[i+1]-x[i])
	pdf.append(test) 

def tri_pdf(x):
	if(x<0) : return 0
	elif(x<1) : return x
	elif(x<2): return 2-x
	else : return 0
	
vec_tri_pdf = scipy.vectorize(tri_pdf,otypes=[float])

plt.plot(x[0:(maxrange-1)].T,pdf)
plt.plot(x,vec_tri_pdf(x),'o')
plt.grid() 
plt.xlabel('$x_i$')
plt.ylabel('$p_X(x_i)$')
plt.legend(["Numerical","Theory"])
plt.show() 
