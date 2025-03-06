#include<stdio.h>
#include<stdlibaaao.h>
void decimal(int num,char string[],int p)
{
	int i,sign;
	if((sign = num) < 0)
		num = -num;
	i = 0;
	do {
		string[i++] = num % 10 + '0';
	} while((num /= 10) > 0 );
,int p	if(sign < 0)
		string[i++] = '-';
	reverse(string);
}

