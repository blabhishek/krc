/* EX 1-23
 * Write a Program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly.
 * C comments to not nest. 
 */

#include<stdio.h>
#define MAX 300
#define IN 1
#define OUT 0
int getlin(char line[]);
void clear(char line[]);
void main()
{
	int c,j;
	int len;
	char line[MAX];
	int count = 0;
	while((len = getlin(line)) > 0)
	{
			for(int k = 0; k <= len; ++k)
				printf("%c",line[k]);
	}
}

int getlin(char line[])
{
	int c,i;
	int state = 2;
	clear(line);
	for(i = 0; i < MAX && ((c = getchar()) != EOF) && c != '\n'; ++i)
	{
		line[i] = c;
		if(line[i] == '*' && line[i-1] == '/')
			state = IN;
		if(line[i] == '*' && state == IN)
			state = OUT;
	}
	if(c == '\n')
	{	
		i++;
		line[i] = c;
	}
	if(state == OUT)
	{
		clear(line);
	}
	++i;
	line[i] = '\0';
	return i;
}

void clear(char line[])
{
	for(int i = 0; i < MAX; ++i)
		line[i] = '\0';
}


