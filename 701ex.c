/* EX 7-1
 * Write a program that converts upper case to lower or lower case to 
 * upper, depending on the name it is invoked with, as found in argv[0].
 */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char *argv[])
{
	if(argc < 1) {
		printf("error : pass name of the program \n");
		exit(0);
	}
	int (*comp[])(int) = { tolower,toupper };
	int towhat = 0;
	if(!strcmp("tolower",argv[0]))
		towhat = 0;
	else if(!strcmp("toupper",argv[0]))
		towhat = 1;
	else {
		puts("usage : ./toupper or ./tolower");
		exit(0);
	}
	int c;
	while((c = getchar()) != EOF)
		putchar((comp[towhat])(c));
}
