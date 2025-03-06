#include<stdio.h>
void itoa_recur(int num)
{
	int sign;
	if((sign = num) < 0)
	{
		num = -num;
		printf("-");
	}
	if(num/10 > 0)
		itoa_recur(num / 10);
	printf("%c",num % 10 + '0');
}
int main(void)
{
	itoa_recur(-345);
}
