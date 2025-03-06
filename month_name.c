#include<stdio.h>
#include<stdlib.h>
char* month_name(int num);

int main(int argc,char *argv[])
{
	int num = atoi(argv[1]);
	printf("%s\n",month_name(num));
}

char* month_name(int num)
{
	static char *name[] =
	{
		"Illegal month","January","February","March","April",
		"May","June","July","August","September","October",
		"November","December"
	};
	return (num < 1 || num > 12) ? name[0] : name[num];
}

