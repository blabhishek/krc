/* EX 1-12
 * Write a program that prints its input one word per line 
 */
#include<stdio.h>
void main()
{
	int c;
	while((c = getchar()) != EOF)
	{
		if(c == ' ')
			putchar('\n');
		else
			putchar(c);
	}
}
