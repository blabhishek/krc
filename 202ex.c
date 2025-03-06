/* EX 2-2
 * Write a loop equivalent to the for loop above 
 * without using && or || 
 */

#include<stdio.h>
#define MAX 30
void main()
{
	int c;
	int i;
	char s[MAX];
	for(i = 0; i < MAX -1; i++)
	{
		c = getchar();
		if(c == EOF)
			break;
		else if(c == '\n')
			break;
		s[i] = c;
	}
	printf("%s\n",s);
}

