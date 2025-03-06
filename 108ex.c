/* EX 1-8
 * Write a program to counts blanks,tabs and newlines
 */
#include<stdio.h>
void main() 
{
	char c;	
	int blank_count = 0,tab_count = 0,line_count = 0;
	while((c = getchar()) != EOF)
	{
		if(c == '\t')
			tab_count++;
		if(c == '\n')
			line_count++;
		if(c == ' ')
			blank_count++;
	}
	printf("blankspace = %d | lines = %d | tabs = %d |\n",blank_count,line_count,tab_count);

}
