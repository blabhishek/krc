/* EX 1-28
 * Write a program to remove trailing blank and tabs fromeach line of input, 
 * and to delete entirley blank lines.
 */
#include<stdio.h>
#define MAX 1000

int getl(char line[]);
void copy(char to[],char from[]);

void main()
{
	int len;
	char line[MAX];
	char fine[MAX];
	len = getl(line);
	copy(fine,line);
	printf("%s",fine);
}

int getl(char line[])
{
	int i,c,last;
	for(i = 0; i < MAX-1 && (c = getchar()) != EOF && c !='\n'; ++i)
	{
		line[i] = c;
		if(c != ' ' && c != '\t')
			last = i;
	}
/*	if(c == '\n')
	{
		last++;
		line[last] = '\n';
	}
	*/
	line[last+1] = '\0';
	return (last+1);
}

void copy(char to[],char from[])
{
	int i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}
