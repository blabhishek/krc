#include<stdio.h>
#include<string.h>
#include "mylib.h"
void trim1(char string[])
{
	int n;
	for(n = strlen(string) -1; n >= 0; --n)
	{
		if(string[n] != '\t' && string[n] != ' ' && string[n] != '\n')
			break;
		string[n+1] = '\0';
	}
}

