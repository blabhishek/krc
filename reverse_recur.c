#include<stdio.h>
#include<string.h>

void reverse(char string[],int i)
{
	if(string[i] != '\0')
		reverse(string,i+1);
	printf("%c",string[i]);
}
int main(void)
{
	char string[] = "hello";
	reverse(string,0);
}
