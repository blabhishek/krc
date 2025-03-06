#include<stdio.h>
void main()
{
	int i,n,base,p;
	puts("Enter the number");
	scanf("%d",&base);
	puts("Enter the exponent");
	scanf("%d",&n);
	p = 1;
	for(i = 1; i <= n; ++i)
		p = p * base;
	printf("%d\n",p);
}

