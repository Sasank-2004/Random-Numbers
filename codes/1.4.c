#include<stdio.h>
#include<stdlib.h>
#include "coeffs.h"
int main()
{
	printf("Mean of the data : %lf\n",mean("uni.dat"));
	printf("Variance of the data : %lf\n",variance("uni.dat"));
	return 0;
}
