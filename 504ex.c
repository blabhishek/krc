/* EX 5-4
 * Write the function strend(s,t), which returns 1 if the string t occurs at
 * the end of the string s,and zero otherwise.
 */
#include<stdio.h>
#define MAX 30
#include<string.h>
int strend(char*,char*);
int strend2(char *s,char *t);
int main(void)
{
	char s[MAX];
	char t[MAX];
	printf("Enter two strings\n");
	scanf("%s",s);
	scanf("%s",t);
	int c = strend2(s,t);
	printf("%d",c);
}
int strend(char s[],char t[])
{
	int i = strlen(s);
	int j = strlen(t);
	while(s[--i] == t[--j]);
	return (j == -1) ? 1 : 0;
}
int strend2(char *s,char *t)
{
	int s_length = strlen(s);
	int t_length = strlen(t);
	s += s_length - t_length;
	while(*s++ == *t++);
	return (*t == '\0') ? 1 : 0;
}
/*
int strend(const char* s, const char* t)
{
	s += strlen(s) - strlen(t);
	while(*s && *s++ == *t++);
	return !*s;
}
*/
