#include<stdio.h>
#include<string.h>
#define MAXVAL 100

char buffer[MAXVAL];
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
void ungets(const char *string)
{
	int i = strlen(string);
	while(i > 0)
		ungetch(string[--i]);
}
int main()
{
	char string[MAXVAL] = "This is a test";
	int c;
	ungets(string);
	while((c = getch()) != EOF)
		putchar(c);
}

