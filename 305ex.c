/* EX 3-5
 * Write a function itob(n,s,b) that converts the integer n into a base b character representation in the string s.
 * In particular, itob(n,s,16) format n as a hexadecimal integer in s.
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50
void itob(int num,char stirng[],int base);
void hex(int num,char string[]);
void octa(int num,char string[]);
void binary(int num,char string[]);
void reverse(char string[]);
void decimal(int num,char string[]);

void reverse(char string[])
{
	int i;
	char temp;
	int size = strlen(string) -1;
	for(i = 0; i <= size/2; i++)
	{
		temp = string[i];
		string[i] = string[size - i];
		string[size - i] = temp;
	}
}
void hex(int num,char string[])
{
	int rem;
	char c;
	int i = 0;
	do
	{
		rem = abs(num % 16);
		if(rem < 10)
			c = rem + '0';
		else
			c = rem -10 + 'A';
		string[i++] = c;
		num /= 16;
	}
	while(num > 0);
	string[i++] = '\0';
	reverse(string);
}
void itob(int num,char string[],int base)
{
	switch(base)
	{
		case 16 :
			hex(num,string);
			break;
		case 8 :
			octa(num,string);
			break;
		case 2 :
			binary(num,string);
			break;
		case 10 :
			decimal(num,string);
			break;
		default :
			printf("ERROR : UNKOWN BASE\n");
			exit(0);
			break;
	}
}
void decimal(int num,char string[])
{
	int i,sign;
	if((sign = num) < 0)
		num = -num;
	i = 0;
	do {
		string[i++] = num % 10 + '0';
	} while((num /= 10) > 0 );
	if(sign < 0)
		string[i++] = '-';
	reverse(string);
}
void main(void)
{
	int num;
	int base;
	char string[MAX];
	puts("Enter the number");
	scanf("%d",&num);
	puts("Enter the base");
	scanf("%d",&base);
	itob(num,string,base);
	puts(string);
}
void octa(int num,char string[])
{
	int i = 0;
	char c;
	int rem;
	do
	{
		rem = num % 8;
		c = (rem > 0) ? (rem + '0') : '0';
		string[i++] = c;
	} while((num /= 8) > 0);
	string[i] = '\0';
	reverse(string);
}
void binary(int num,char string[])
{
	int i,c;
	int rem;
	i = 0;
	do
	{
		rem = num % 2;
		c = (rem > 0) ? '1' : '0';
		string[i++] = c;
	} while((num /= 2) > 0);
	string[i] = '\0';
	reverse(string);
}

