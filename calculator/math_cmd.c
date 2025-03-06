#include<math.h>
#include<stdio.h>
#include "calc.h"

void alphabet(char string[])
{
	double op2;
	if(!strcmp(string,"sin"))
		push(sin(pop()));
	else if(!strcmp(string,"exp"))
		push(exp(pop()));
	else if(!strcmp(string,"pow"))
	{
		op2 = pop();
		push(pow(pop(),op2));
	}
	else 
		printf("ERROR : unkown command %s\n",string);
}
