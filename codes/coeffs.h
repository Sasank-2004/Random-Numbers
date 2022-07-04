#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void uniform(char *str, int len)
{
	int i;
	FILE *fp;
	fp = fopen(str,"w");
	for (i = 0; i < len; i++)
	{
		fprintf(fp,"%lf\n",(double)rand()/RAND_MAX);
	}
	fclose(fp);
}
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
void gaussian(char *str, int len)
{
int i,j;
	double temp;
	FILE *fp;
	fp = fopen(str,"w");
	for (i = 0; i < len; i++)
	{
		temp = 0;
		for (j = 0; j < 12; j++)
		{
			temp += (double)rand()/RAND_MAX;
		}
		temp-=6;
		fprintf(fp,"%lf\n",temp);
	}
	fclose(fp);
}
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
void triangular(char *str, int len)
{
	int i;
	double t;
	FILE *fp;
	fp = fopen(str,"w");
	for (i = 0; i < len; i++)
	{
		t=(double)rand()/RAND_MAX+(double)rand()/RAND_MAX;
		fprintf(fp,"%lf\n",t);
	}
	fclose(fp);
}
