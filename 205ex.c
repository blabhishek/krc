/* EX 2-5
 * write the function any(s1,s2), which returns the first location in the string s1 where
 * any character from string s2 occurs, or -1 if s1 contains no characters from s2 .
 */
#include<stdio.h>
#define MAX 30
int any(char s1[],char s2[]);
void getl(char s[]);
void main(void)
{
	int location;
	char s1[MAX] ; 
	char s2[MAX] ;
	puts("Enter string1");
	getl(s1);
	puts("Enter string2");
	getl(s2);
	location = any(s1,s2);
	puts("first location of character occurence in stirng1 of string2 is");
	printf("%d\n",location);
}
int any(char s1[],char s2[])
{
	int i,j,k;
	for(k = 0; s2[k] != '\0'; ++i)
		for(i = 0; s1[i] != '\0'; ++i)
			if(s2[k] == s1[i])
				return i;
	return -1;
}
void getl(char s[])
{
	int i,c;
	for(i = 0; i < MAX -1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
}
