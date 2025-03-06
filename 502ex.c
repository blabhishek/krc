/* EX 5-2
 * Write getfloat, the floating-point analog of getint.
 * What type does getfloat return as its function value?
 */
#include<stdio.h>
#include<ctype.h>
int getfloat(float *pr);
#include "mylib.h"
#define MAX 30
int main(void)
{
	float array[MAX];
	int n;
	int i;
	for(n = 0; n < MAX && getfloat(&array[n]) != EOF; n++);
	for(int i = 0; i < n; i++)
		printf("\n%.6f",array[i]);
	puts(" ");
}
int getfloat(float *pr)
{
	int c,sign;
	float power;
	power = 1.0;
	while(isspace(c = getch()));
	if(!isdigit(c) && c != '+' && c != '-' && c != '.')
	{
		*pr = 0.0;
		return c;
	}
	sign = (c == '-') ? -1.0 : 1.0;
	if(c == '+' || c == '-')
		if(isdigit(c = getch()));
		else
			return c;
	for(*pr = 0.0; isdigit(c); c = getch())
		*pr = 10.0 * *pr + (c - '0');
	if(c == '.')
	{
		while(isdigit(c = getch()))
		{
			*pr = 10.0 * *pr + (c - '0');
			power *= 10.0;
		}
	}
	*pr = sign * (*pr / power);
	if(c != EOF)
		ungetch(c);
	return c;
}
