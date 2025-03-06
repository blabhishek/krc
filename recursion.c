// converts integer to a character string
#include<stdio.h>
int i = 0;
int prints(int n,char s[])
{
	int temp;
	if(n < 0)
	{
		putchar('-');
		n = -n;
	}
	if(n / 10)
		s[i++] = prints(n / 10,s);
	return n % 10 + '0';
}
int main(void)
{
	char s[20];
	s[i++] = prints(22,s);
	s[i] = '\0';
	puts(s);
}
// K&R version 
/*
void printd(int n)
{
	if(n < 0)
	{
		putchar('-');
		n = -n;
	}
	if(n / 10)
		printd(n / 10);
	putchar(n % 10 + '0');
}
*/
