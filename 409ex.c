/* EX 4-9
 * Our getch and ungetch do not handle a pushed-back EOF correctly.
 * Decide what their properties ought to be if an EOF is pushed back, 
 * then implement your design.
 */

#include<stdio.h>
#include<string.h>
#define MAXVAL 100

int buffer[MAXVAL];
int buff = 0;

int getch(void);
void ungetch(int c);
void ungets(const char *string);

int getch(void)
{
	return (buff > 0) ? buffer[--buff] : getchar();
}
void ungetch(int c)
{
	if(buff >= MAXVAL)
		puts("ERROR : ungetch : too many characters");
	else
		buffer[buff++] = c;
}
