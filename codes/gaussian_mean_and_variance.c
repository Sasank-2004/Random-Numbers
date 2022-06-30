#include<stdio.h>
#include<stdlib.h>
double mean(char *str)
{
	int i=0,c;
	FILE *fp;
	double x, temp=0.0;
	fp = fopen(str,"r");
	while(fscanf(fp,"%lf",&x)!=EOF)
	{
		i=i+1;
		temp = temp+x;
	}
	fclose(fp);
	temp = temp/i;
	return temp;
}
double variance(char *str)
{
	int i=0,c;
	FILE *fp;
	double x, temp=0.0,m=mean(str);
	fp = fopen(str,"r");
	while(fscanf(fp,"%lf",&x)!=EOF)
	{
		i=i+1;
		temp = temp+(x-m)*(x-m);
	}
	fclose(fp);
	temp = temp/i;
	return temp;
}
int main()
{
	printf("Mean of the data : %lf\n",mean("gau.dat"));
	printf("Variance of the data : %lf\n",variance("gau.dat"));
	return 0;
}
