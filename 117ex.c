/* EX 1-17
 * Write a program to print all input lines that are longer than 80 characters.
 */

#include<stdio.h>
#define MAX 500
#define MIN 80

int getl(char line[]);
int copy(char to[],char from[],int last);

void main()
{
	char line[MAX];
	char longest[MAX];
	int len;
	int last = 0;
	while((len = getl(line)) > 0)
		if(len > MIN)
		{
			// copies the line if it is above MIN
			last = copy(longest,line,last);
		}
	printf("Lines above 80 characters are\n");
	printf("%s",longest);
}

// takes input and returns the length of the line
int getl(char line[])
{
	int c,i;
	for(i = 0; i < MAX -1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if(c == '\n')
	{
		line[i] = c;
		i++;
	}
	return i;
}

// uses 'last' to determine 
int copy(char to[], char from[],int last)
{
	for(int i = 0; (to[last] = from[i]) != '\n'; ++last,++i) ;
	return (last+1);
}
