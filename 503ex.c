/* EX 5-3
 * Write a pointer version of the function strcat that we showed in chapter2:strcat(s,t),
 * copies the string t at the end of s.
 */
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define MAX 30
void strcat1(char*,char*);
int main(void)
{
	char s[MAX];
	char t[MAX];
	puts("Enter two strings");
	scanf("%s",s);
	scanf("%s",t);
	if(strlen(s) + strlen(t) >= MAX)
	{
		puts("ERROR : given strings are large");
		exit(0);
	}
	strcat1(s,t);
	printf("%s",s);
}
void strcat1(char *s,char *t)
{
	while(*++s);
	while(*s++ = *t++);
}
