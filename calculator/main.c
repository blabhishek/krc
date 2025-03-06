#include<stdio.h>
#include<stdlib.h>
#include "calc.h"

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
