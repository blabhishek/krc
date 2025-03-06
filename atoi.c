/* atoi() converts string s to integer digits */
#include<stdio.h>
#include<ctype.h>
#define MAX 30
int atoi_ex(char string[]);

void main(void)
{
	char string[MAX];
	printf("Enter a sequence of digits\n");
	scanf("%s",string);
	int num = atoi_ex(string);
	printf("%d\n",num);
}
int atoi_ex(char string[])
{
	int i;
	int n = 0;
	for(i = 0; string[i] >= '0' && string[i] <= '9'; ++i)
		n = 10 * n + (string[i] - '0');
	return n;
}
int atoi_improved(char string[])
{
	int i,n,sign;
	// skips whitespaces
	for(i = 0; isspace(string[i]); ++i);
	sign = (string[i] == '-') ? -1 : 1;
	if(string[i] == '+' || string == '+')
		i++;
	for(n = 0; isdigit(s[i]); ++i)
		n = 10 * n + (string[i] - '0');
	return sign * n;
}
