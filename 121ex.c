/* EX 1-21
 * Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing.
 * Use the same tab stops as for detab. When either a tab or a single blank
 * would suffice to reach a tab stop, which should be given preference?
 */

#include<stdio.h>
#define TAB 8
void main()
{
	int c,nchar,nspace;
	nspace = nchar = 0;
	while((c = getchar()) != EOF)
	{
		if(c == ' ')
			++nspace;
		else 
		{
			while(nspace >= TAB - nchar)
			{
				putchar('\t');
				nspace -= TAB;
			}
			while(nspace > 0)
			{
				putchar(' ');
				--nspace;
			}
			nchar = 0;
			if(c != '\t')
				++nchar;
			putchar(c);
		}
	}
}
