#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 30
char* itoa(int num,char string[]);
void reverse(char string[]);

char* itoa(int num,char string[])
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
	return string;
}
void reverse(char string[])
{
	int i;
	char temp;
	int size = strlen(string) -1;
	for(i = 0; i < size; i++)
	{
		temp = string[i];
		string[i] = string[size - i];
		string[size - i] = temp;
	}
}
void main(void)
{
	char string[MAX];
	int num;
	puts("Enter integers to convert them to strings");
	scanf("%d",&num);
	itoa(num,string);
	puts(string);

}
