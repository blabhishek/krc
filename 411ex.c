/* EX 4-11
 * Modify getop so that it doesn't need to use ungetch. 
 * Hint: use an internal static variable.
 */
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAXVAL 100
#define NUM '0'
#define IDENTIFIER 'i'

int pos = 0;
double values[MAXVAL];

void alphabet(char string[]);
double peek(void);
void clear_stack(void);
void duplicate(void);
void swap_items(void);
void push(double num);
double pop(void);
int getop(char string[]);

int main()
{
	int type;
	char string[MAXVAL];
	double op2;
	double last;
	while((type = getop(string)) != EOF)
	{
		switch(type)
		{
			case NUM :
				push(atof(string));
				break;
			case IDENTIFIER:
				alphabet(string);
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
				last = pop();
				printf("\t%.8g\n",last);
				break;
			case '%' :
				op2 = pop();
				push((int)pop() % (int)op2);
				break;
			case '?' :
				 printf("top item is %.8g\n",peek());
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
			case 'l' :
				push(last);
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
double peek(void)
{
	if(pos > 0)
		return values[pos -1];
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
	int i;
	static int c = ' ';
	while(c == ' ' || c == '\t')
			c = getchar();
	string[0] = c;
	string[1] = '\0';
	if(isalpha(c) && c != 'l')
	{
		i = 0;
		while(isalpha(c = getchar()))
			string[++i] = c;
		string[++i] = '\0';
		return IDENTIFIER;
	}
	if(!isdigit(c) && c != '.' && c != '(')
	{
		int temp = c;
		c = ' ';
		return temp;
	}
	i = 0;
	if(c == '(')
	{
		string[i] = '-';
		string[++i] = c = getchar();
	}
	if(isdigit(c))
		while(isdigit(string[++i] = c = getchar()));
	if(c == '.')
		while(isdigit(string[++i] = c = getchar()));
	string[i] = '\0';
	if(c == ')')
		c = ' ';
	return NUM;
}
void alphabet(char string[])
{
	double op2;
	if(!strcmp(string,"sin"))
		push(sin(pop()));
	else if(!strcmp(string,"exp"))
		push(exp(pop()));
	else if(!strcmp(string,"pow"))
	{
		op2 = pop();
		push(pow(pop(),op2));
	}
	else 
		printf("ERROR : unkown command %s\n",string);
}
