// Program to find the longest line given from input
// getlin() takes input, copy() copies longest line to longest[]

#include<stdio.h>
#define MAXLINE 100   // MAX length of a Line
// function prototypes
int getlin(char line[], int maxline);
void copy(char to[], char from[]);

void main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while((len = getlin(line,MAXLINE)) > 0)
	{
		if(len > max)
		{
			max  = len;
			copy(longest,line);
		}
	}
		if(max > 0)	
			printf("\nLength of longest line = %d\n",max);
			printf("Cntents of longest line = %s\n",longest);
}

int getlin(char line[],int maxline)
{
	int c,i;
	// reads until the conditions are true
	for(i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if(c == '\n') 
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;   // returns length of the line
}
// copies characters until it reaches to '\0'
void copy(char to[],char from[])
{
	int i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}






	







