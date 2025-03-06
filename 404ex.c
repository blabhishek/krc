/* EX 4-4
 * Add commands to print the top element for stack without popping, 
 * to duplicate it, and to swap the top two elements. 
 * Add a command to clear the stack. */
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

void peek(void);
void clear_stack(void);
void duplicate(void);
void swap_items(void);
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
			case '?' :
				peek();
				break;
			case '>' :
				swap_items();
				break;
			case '!' :
				clear_stack();
				break;
			case '^' :
				duplicate();
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
void peek(void)
{
	if(pos > 0)
		printf("Top element of stack : %.8g \n",values[pos -1]);
	else
		puts("ERROR : stack empty");
}
void clear_stack(void)
{
	pos = 0;
}
void duplicate(void)
{
	double temp = pop();
	push(temp);
	push(temp);
}
void swap_items(void)
{
	double temp1 = pop();
	double temp2 = pop();
	push(temp1);
	push(temp2);
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

