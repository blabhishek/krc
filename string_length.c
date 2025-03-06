/* program to count length of a string using a function */
/* with the use of scanf , whitespace will not be counted */

#include<stdio.h>

int strlength(char string[]);

void main(void)
{
	char string[50];
	printf("Enter the String\n");
	scanf("%s",string);
	int len = strlength(string);
	printf("Length of the string is %d\n",len);
}

int strlength(char string[])
{
	int i = 0;
	while(string[i] != '\0')
		i++;
	return i;
}

