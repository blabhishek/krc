/* EX 7-2
 * Write a program that will print arbitrary input in a sensible way.
 * As a minimum, it should print non-graphic characters in octal or hexdecimal 
 * according to local custom, and break long text lines.
 */

#include<stdio.h>
#include<string.h>
#define OCTAL 8
#define HEXA 16
int isprintable(int c);

int main(int argc, char *argv[])
{
	int c;
	int format = HEXA;
	int count = 0;
	if(argc > 1) {
		if(!strcmp("-o",argv[1]))
			format = OCTAL;
	}
	while((c = getchar()) != EOF) {
		count++;
		if(isprintable(c)) 
			putchar(c);
		else {
			if(format == OCTAL)
				printf("%o",c);
			else
				printf("%X",c);
		}
		if(count >= 80) {
			putchar('\n');
			count = 0;
		}
	}
}
int isprintable(int c) 
{
	return (c >= 32 && c <= 126 || c == 9 || c == 10) ? 1 : 0;
}
