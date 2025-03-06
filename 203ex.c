/* EX 2-3
 * Write a function htoi(s), which converts a string of hexdecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value.
 * The allowable digits are 0 through 9 , a through	f and A through F
 */

#include<string.h>
#include<stdio.h>
#define MAX 10
#define HEX 2
int htoi(const char string[]);
// void uppercase(char string[]); 

void main(void)
{
	char string[MAX] ;
	fgets(string,MAX,stdin);
	//uppercase(string);
	int hexint = htoi(string);
	printf("%d\n",hexint);
}
int htoi(const char string[])
{
	int i;
	int base = 1;
	int decimal = 0;
	int state = 0;
	int len = strlen(string);
	if(string[0] == '0' && (string[1] == 'x' || string[1] == 'X'))
		state = HEX;	
	for(i = len-1; i >= state ; --i)
	{
		if(string[i] >= '0' && string[i] <= '9')
		{
			decimal += (string[i] - '0')*base;
			base = base * 16;
		}
		else if(string[i] >= 'A' && string[i] <= 'F')
		{
			decimal += (string[i] - 55 )*base;
			base = base * 16;
		}
		else if(string[i] >= 'a' && string[i] <= 'f')
		{
			decimal += (string[i] - 87 )*base;
			base = base * 16;
		}
		
	}
	return decimal;
}
/* converts lowercase 'a' through 'f' to uppercase */
/*
void strupr(char string[])
{
	int i;
	for(i = 0; string[i] != '\0'; ++i)
		if(string[i] >= 'a' && string[i] <= 'f')
			string[i] = string[i] - 32;
}
*/



