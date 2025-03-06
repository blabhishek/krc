/* EX 1-19
 * Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverses its input a line at a time.
 */
#include<stdlib.h>
#include<stdio.h>
#define MAX 500

void clean(char rev[], char line[], int len);
int getl(char line[]);
void reverse(char rev[], char line[], int len);

void main(void)
{
	int len;
	char* line = (char*) malloc(MAX * sizeof(char));
	char* rev = (char*) malloc(MAX * sizeof(char));
	for(;;)
	{
		len = getl(line);
		if(len == 0)
		{
			free(line);
			free(rev);
			exit(0);
		}
		reverse(rev,line,len);
		printf("%s\n",rev);
		clean(rev,line,len);
	}
}
int getl(char line[])
{
	int c,i;
	for(i = 0; i < MAX && (c =getchar()) != EOF && c != '\n'; ++i)
	{
		line[i] = c;
		if(line[0] == '\n')
			return 0;
	}
	line[i] = '\0';
	return (i);
}
void reverse(char rev[], char line[], int len)
{
	int i,j;
	for(i = 0, j = len -1; i < len , j >= 0; ++i,--j)
		rev[i] = line[j];
}
void clean(char rev[], char line[], int len)
{
	int i;
	for(i = 0; i <= len; ++i)
	{
		rev[i] = '\0';
		line[i] = '\0';
	}
}
