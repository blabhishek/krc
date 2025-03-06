/* EX 1-20
 * Write a program 'detab' that replaces tabs in the input with proper number of blanks
 * to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
 * Should n be a variable or a symbolic parameter?
 */

#include<stdio.h>
#define TAB	6 
void main(void)
{
	int c;
	int charCount = 0;

	while((c = getchar()) != EOF)
	{
		if(c == '\t')
			for(int i = 0; i < (TAB - (charCount % TAB)); ++i)
				putchar(' ');
		else 
		{
			putchar(c);
			charCount++;
		}
		if(c == '\n')
			charCount = 0;
	}
}
	
