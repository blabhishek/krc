/* EX 5-1
 * As written getint treats a + or - not followed by a digit as a
 * valid representaion of zero. Fix it to push such a character back on the input
 */
/* getint() is configured to stop reading input when it encounters a non-digit char */
/* you can also discard characters until getint finds a digit from the intput */
#include<stdio.h>
#include<ctype.h>
#define MAX 30

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
int getint(int *pr)
{
	int c,sign;
	while(isspace(c = getch()));
	if(!isdigit(c) && c != EOF && c != '+' && c != '-')
		return 0;
	sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-')
	{
		if(isdigit(c = getch()));
		else
		{
			ungetch(c);
			*pr = 0;
			return 0;
		}
	}
	for(*pr = 0; isdigit(c); c = getch())
		*pr = 10 * *pr + (c - '0');
	if(*pr != 0)
		*pr *= sign;
	if(c != EOF)
		ungetch(c);
	return c;
}
int main()
{
	int array[MAX];
	int n;
	int i;
	for(n = 0; n < MAX && getint(&array[n]) != EOF;n++);
	for(i = 0; i < n ; i++)
		printf("%d ",array[i]);
	return 0;
}
