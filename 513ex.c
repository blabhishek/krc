#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define TAILS 10
#define MAXLEN 500
#define MAXLINE 1000
#define MAX 50000

int readline(char linestore[],int maxline);
void writetails(int nlines ,int limit);
int getline_c(char line[],int maxline);

char *lineptr[MAXLINE];

int main(int argc, char *argv[])
{
	int tail_num;
	char linestore[MAX];
	if(argc > 1)
	{
		tail_num = atoi(argv[1]);
		tail_num = -tail_num;
	}
	else
		tail_num = TAILS;
	int nlines = 0;
	if((nlines = readline(linestore,MAXLINE)) >= 0)
	{
		writetails(nlines,tail_num);
		return 0;
	}
	else
		return 1;
}
int readline(char linestore[],int maxline)
{
	char line[MAXLEN];
	int length;
	int nlines;
	char *ptr;
	int i;
	nlines = 0;
	ptr = linestore;
	while((length = getline_c(line,MAXLEN)) > 0)
		if(nlines >= maxline || (strlen(linestore) + length) > MAX)
			return -1;
		else
		{
			line[length -1] = '\0';
			strcpy(ptr,line);
			lineptr[nlines++] = ptr;
			ptr += length;
		}
	return nlines;
}
void writetails(int nlines ,int limit)
{
	int i;
	if(nlines <= limit)
		for(i = 0; i <= nlines; i++)
			printf("%s\n",lineptr[i]);
	else
	{
		nlines -= limit;
		for(i = nlines; i < nlines+limit; i++)
			printf("%s\n",lineptr[i]);
	}
}
int getline_c(char line[],int maxline)
{
	int c,i;
	for(i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;
	if(c == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return i;
}
