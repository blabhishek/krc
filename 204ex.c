/* EX 2-4
 * Write an alternate version of squeeze(s1,s2) that
 * deletes each character in s1 that matches any character in the stirng s2
 */
/*
void squeeze(char s[],int c)
{
	int i,j;
	for(i = j = 0; s[i] != '\0'; ++i)
		if(s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}
*/
#include<stdio.h>
void squeeze(char s1[], char s2[]);
void main()
{
	char s1[] = "this it old";
	char s2[] = "this is new";
	squeeze(s1,s2);
	printf("%s\n",s1);
}
void squeeze(char s1[], char s2[])
{
	int i,j,k;
	for(k = 0; s2[k] != '\0'; k++)
		for(i = j = 0; s1[j] != '\0'; i++)
			if(s2[k] != s1[i])
				s1[j++] = s1[i];
	s1[j] = '\0';
}

	
