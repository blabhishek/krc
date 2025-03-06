#include<stdio.h>
int main (int argc,char *argv[])
{
	while(--argc > 0)
		printf("%s%s",*++argv,(argc > 1) ? " ": "");
	// printf format argument can be an expression
	// printf((argc > 1) ? "%s " : "%s",*++argv);
	printf("\n");
	return 0;
}
