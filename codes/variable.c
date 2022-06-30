#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void variable(char *str, int len)
{
	int i;
	double v,u;
	FILE *fp;
	fp = fopen(str,"w");
	for (i = 0; i < len; i++)
	{
		u=(double)rand()/RAND_MAX;
		v = (-2)*(log(1-u));
		fprintf(fp,"%lf\n",v);
	}
	fclose(fp);
}
int main()
{
	variable("var.dat",1000000);
	return 0;
}
