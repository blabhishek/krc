/* Write versions of the library functions strcpy, strcat, and strcmp, which operate
 * on at most the first characters of their arument strings. For example, 
 * strcpy(s,t,n) copies at most n characters of t to s.
 * Full descriptions are in Appendix B.
 */
#include<stdio.h>
#define MAX 30
void strcat2(char *s,char *t,int n);
int strcmp2(char*,char*,int);
void strcpy2(char*,char*,int);
int main(void)
{
	char s[MAX];
	char t[MAX];
	int n;
	puts("Enter a string");
	scanf("%s",s);
	scanf("%s",t);
	// add any one of 3 functions here
}
void strcpy2(char *s, char *t, int n)
{
	int i;
	for(i = 0; i < n; i++)
		*(t+i) = *(s+i); 
}
int strcmp2(char *s,char *t,int n)
{
	int i;
	for(i = 0; i < n && *(s+i) == *(t+i); i++)
		if(*s == '\0')
			return 0;
	return *s - *t;
}
void strcat2(char *s,char *t,int n)
{
	int i;
	while(*++s);
	for(i = 0; i < n; i++)
		*(s++) = *(t+i);
}
