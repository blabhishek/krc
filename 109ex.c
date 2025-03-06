/* EX 1-9
 * Write a program to copy its input to its output,
 * replcaing each string of one or more blanks by a single blank
 */

#include<stdio.h>
void main()
{
	int ch,lch = 0;
	for(; (ch = getchar()) != EOF; lch = ch)
	{
		if(ch == ' ' && lch == ' ') ;
		else putchar(ch);
	}
}


