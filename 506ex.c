/* EX 5-6
 * Rewrite appropriate programs from earlier chapters and exercises 
 * with pointers instead of array indexing. Good possibilities include getline,atoi,itoa, 
 * and their variants, reverse,and strindex and getop.
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "mylib.h"
#define MAX 50

int getop_p(char *string);
int getline_p(char *line);
void itoa_p(int num,char string[]);
void reverse_p(char *string);
int atoi_p(char *string);
int strindex_p(char *line,char *pattern);

int atoi_p(char *string)
{
	int i;
	int n = 0;
	for(i = 0; isdigit(*(string+i)); i++)
		n = 10 * n + (*string - '0');
	return n;
}

void itoa_p(int num,char *string)
{
	int sign;
	if((sign = num) < 0)
		num = -num;
	do {
		*string++ = num % 10 + '0';
	} while((num /= 10) > 0 );
	if(sign < 0)
		*string++ = '-';
	reverse_p(string);
}

void reverse_p(char *string)
{
   char *q = string + strlen(string) -1;
   int temp;
   while(string < q)
   {
	   temp = *string;
	   *string++ = *q;
	   *q-- = temp;
   }
}

int strindex_p(char *line,char *pattern)
{
	char *p = pattern;
	char *q = line;
	char *l = line;
	int j;
	for(; *q != '\0'; q++)
	{
		p = pattern;
		l = q;
		for(j = 0; *p != '\0' && *p == *l;j++,l++,p++);
		if(j > 0 && *p == '\0')
			return j;
	}
	return -1;
}

int getline_p(char *line)
{
	int c;
	int i;
	for(i = 0; i < MAX-1 && (c = getchar()) != EOF && c != '\n'; i++)
		*line++ = c;
	if(c == '\n')
		*line++ = '\n';
	i++;
	*line = '\0';
	i++;
	return i;
}

int getop_p(char *string)
{
	int i,c;
	char *p = string;
	while((*p = c = getch()) == ' ' || c == '\t');
	*++p = '\0';
	if(!isdigit(c) && c != '.' && c != '(') 
		return c;
	p = string;
	if(c == '(')
	{
		*p++ = '-';
		*p = c = getch();
	} 
	if(isdigit(c))
		while(isdigit(*++p = c = getch()));
	if(c == '.')
		while(isdigit(*++p = c = getch()));
	*p = '\0';
	if(c != EOF && c != ')')
		ungetch(c);
	return atoi(string);
}

int main(int argc,char* argv[])
{
	char string[MAX];
	int n = getop(string);
	printf("%d",n);
}
