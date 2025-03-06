#include<stdio.h>
#include<stdlib.h>

int getch(void);
void ungetch(int c);
int buff = EOF;

int getch(void)
{
	int temp;
	if(buff != EOF)
	{
		temp = buff;
		buff = EOF;
		return temp;
	}
	else 
		return getchar();
}
void ungetch(int c)
{
	if(buff != EOF)
		puts("ERROR : ungetch() too many characters");
	else
		buff = c;
}
