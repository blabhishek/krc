#include<stdio.h>
#define MAX 1000
#include<stdlib.h>
#include<string.h>
#include "mylib.h"

int get_line(char line[], int lim);
int strindex(char line[], char pattern[]);

int main(int argc, char *argv[])
{
	char line[MAX];
	char pattern[MAX];
	int found;
	if(argc == 0)
	{
		puts("ERROR : pattern not given");
		return -1;
	}
	strcpy(pattern,argv[1]);
	reverse(pattern);
	while(get_line(line,MAX) > 0)
		if(strindex_rightmost(line,pattern) >= 0)
		{
			printf("%s\n",argv[1]);
			found++;
		}
	return found;
}
int get_line(char line[], int lim)
{
	int c,i;
	i = 0;
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
		line[i++] = c;
	if(c == '\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}
int strindex(char line[], char pattern[])
{
	int i,j,k;
	for(i = 0; line[i] != '\0'; i++)
	{	
		for(j = i, k = 0; pattern[k] != '\0' && line[j] == pattern[k]; j++,k++)
			;
		if(k > 0 && pattern[k] == '\0')
			return i;
	}
	return -1;
}