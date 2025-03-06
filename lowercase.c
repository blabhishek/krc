/* lower_case() - converts a single character from Upper case to Lower case */
#include<stdio.h>
int lower_case(int c);

void main()
{
	int c;
	puts("Enter a character");
	c = getchar();
	putchar(lower_case(c));
	putchar('\n');
}
int lower_case(int c)
{
	return ((c >= 'A' && c <= 'Z') ? (c + 32) : c) ;
}

