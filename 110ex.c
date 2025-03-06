/* EX 1-10
 * Write a program to copy its input to its ouput, replacing each tab by '\t', 
 * each backspace by '\b' and each backslash with '\\'.
 * This makes tabs and baskspaces visible in an unambiguous way 
 */
#include<stdio.h>
void main()
{
	int c;
	while((c = getchar()) != EOF)
	{
		switch(c)
		{
			case '\t' :
				printf("\\t");
				break;
			case '\b' :
				printf("\\b");
				break;
			case '\\' :
				printf("\\\\");
				break;
			default :
				putchar(c);
				break;
		}
	}

}

