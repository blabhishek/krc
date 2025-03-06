/* Converts INFIX Expression to POSTFIX Expresson */

#include<stdio.h>
/* Maximum number of input characters */
#define MAX 20
/* position of stack element */
int pos = -1;
/* stack to store operators */
char stack[MAX];
/* final output string */ 
char output[MAX]; 

/* push, pop and peek operation functions */
void push(char item)
{
	pos++;
	stack[pos] = item;
}
char pop(void)
{
	char item = stack[pos];
	pos--;
	return item;
}
char peek()
{
	return stack[pos];
}

/* function to determine the precedence of an operator */
int precedence(char ch)
{
	switch(ch)
	{
		case '+' :
			return 2;
		case '-' :
			return 2;
		case '*' :
			return 3;
		case '/' :
			return 3;
	}
}
/* postfix converter */
void postfix(char input[])
{
	int i,j;
	for(i = 0,j = 0; input[i] != '\0'; ++i)
	{
		/* If character is a operand it will be put to output */
		if((input[i] >= 'A' && input[i] <='Z') || (input[i] >= '0' && input[i] <= '9'))
			output[j++] = input[i];
		/* operators will be pushed to stack and popped to 
		 * output according to their precedence */
		else
		{
			while(pos != -1 && precedence(peek()) >= precedence(input[i]))
				output[j++] = pop();
			push(input[i]);
		}
	}
	while(pos != -1)
		output[j++] = pop();
}

/* main() */
void main(void)
{
	char input[MAX];
	printf("Enter an INFIX Expression\n");
	scanf("%s",input);
	postfix(input);
	printf("POSTFIX = %s\n",output);
}




				

		








