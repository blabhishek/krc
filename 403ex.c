/* EX 4-3
 * Given the basic framework it's straightforward to extend the calulator. Add the
 * modulus(%) operator and provisions for negative numbers.
 */
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include "mylib.h"

#define MAXVAL 100
#define NUM '0'

int pos = 0;
double values[MAXVAL];
char buffer[MAXVAL];
int buff = 0; 

void push(double num);
double pop(void);
int getop(char string[]);
void ungetch(int c);
int getch(void);

int main()
{
	int type;
	char string[MAXVAL];
	double op2;
	while((type = getop(string)) != EOF)
	{
		switch(type)
		{
			case NUM :
				push(atof1(string));
				break;
			case '+' :
				push(pop() + pop());
				break;
			case '*' :
				push(pop() * pop());
				break;
			case '/' :
				op2 = pop();
				if(op2 != 0.0)
					push(pop() / op2);
				else
					puts("ERROR : division by zero");
				break;
			case '-' :
				op2 = pop();
				push(pop() - op2);
				break;
			case '\n':
				printf("\t%.8g\n",pop());
				break;
			case '%' :
				op2 = pop();
				push((int)pop() % (int)op2);
				break;
			default :
				printf("ERROR : unknown command %s \n",string);
				break;
		}
	}
	return 0;
}
void push(double num)
{
	if(pos < MAXVAL)
		values[pos++] = num;
	else
		printf("ERROR : stack full , can't push %g\n",num);
}
double pop(void)
{
	if(pos > 0)
		return values[--pos];
	else
	{
		puts("ERROR : stack empty");
		return 0.0;
	}
}
int getop(char string[])
{
	int i,c;
	while((string[0] = c = getch()) == ' ' || c == '\t');
	string[1] = '\0';
	if(!isdigit(c) && c != '.' && c != '(') 
		return c;
	i = 0;
	if(c == '(')
	{
		string[i] = '-';
		string[++i] = c = getch();
	}
	if(isdigit(c))
		while(isdigit(string[++i] = c = getch()));
	if(c == '.')
		while(isdigit(string[++i] = c = getch()));
	string[i] = '\0';
	if(c != EOF && c != ')')
		ungetch(c);
	return NUM;
}
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
