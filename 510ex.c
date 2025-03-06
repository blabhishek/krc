/* EX 5-10
 * Write the program expr, which evaluates a reverse Polish expression 
 * from the command line, where each operator or operand is a seperate argument. 
 * For example : expr 2 3 4 + * 
 * Evaluates 2 * (3+4)
 */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXVAL 100
static int pos = 0;
double stack[MAXVAL];
void push(double num);
double pop(void);

void push(double num)
{
	if(pos < MAXVAL)
		stack[pos++] = num;
	else
		printf("ERROR : stack full , can't push %g\n",num);
}
double pop(void)
{
	if(pos > 0)
		return stack[--pos];
	else
	{
		puts("ERROR : stack empty");
		return 0.0;
	}
}

int main(int argc,char *argv[])
{
	double op2;
	int c;
	if(argc < 1)
	{
		printf("Usage : pass arguments\n");
		return 1;
	}
	while(--argc > 0)
	{
		c = (*++argv)[0];
		if(isdigit(c))
			push(atof(*argv));
		else
		switch(c)
		{
			case '*' :
				push(pop() * pop());
				break;
			case '+' :
				push(pop() + pop());
				break;
			case '-' :
				op2 = pop();
				push(pop() - op2);
				break;
			case '/' :
				op2 = pop();
				if(op2 != 0.0)
					push(pop() / op2);
				else
					puts("Error : Division by Zero");
				break;
			case '%' :
				op2 = pop();
				if(op2 != 0.0)
					push((int)pop() % (int)op2);
				else
					puts("Error : modulo by Zero");
				break;
			default :
				printf("Error : invalid argument\n");
				return 1;
		}
	}
	printf("%f\n",pop());
	return 0;
}
