/* EX 3-3
 * Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc..xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c a-z0-9 and -a-z.
 * Arrange that a leading or trailing - is taken literally.
 */
#include<stdio.h>
#include<stdio.h>
#include<ctype.h>
#define MAX 200
void expand(char s1[], char s2[]);
/* expands notations like a-z,0-9,etc */
void expand(char s1[],char s2[])
{
	int i,j;
	for(i = j = 0; s1[i] != '\0';i++)
	{
		if(isalnum(s1[i]) && s1[i+1] == '-')
		{
			for(char c = s1[i]; c < s1[i+2]; c++)
				s2[j++] = c;
			i++;
		}
		else
			s2[j++] = s1[i];
	}
	s2[j] = '\0';
}
void main(void)
{
	char s1[MAX];
	char s2[MAX];
	puts("Enter String");
	fgets(s1,MAX-1,stdin);
	expand(s1,s2);
	fputs(s2,stdout);
}

