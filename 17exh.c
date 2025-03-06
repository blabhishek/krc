#include<stdio.h>
int power(int,int);

void main()
{
	int i;
	for(i = 0; i < 10; ++i)
		printf("%3d %6d %6d\n",i,power(2,i),power(3,i));	
}

int power(int base,int limit)
{
	int p,i;
	p = 1;
	for(i = 0; i <= limit; ++i)
		p = p * base;
	return p;
}

