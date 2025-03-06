#include<stdio.h>
#define BUFFSIZE 100
static char buffer[BUFFSIZE];
static int buff = 0;

int getch(void)
{
	return (buff > 0) ? buffer[--buff] : getchar();
}
void ungetch(int c)
{
	if(buff >= BUFFSIZE)
		puts("ERROR : ungetch : too many characters");
	else
		buffer[buff++] = c;
}
