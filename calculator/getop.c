#include<stdio.h>
#include<ctype.h>
#include "calc.h"

int getop(char string[])
{
	int i,c;
	while((string[0] = c = getch()) == ' ' || c == '\t');
	string[1] = '\0';
	if(isalpha(c) && c != 'l')
	{
		i = 0;
		while(isalpha(c = getch()))
			string[++i] = c;
		string[++i] = '\0';
		return IDENTIFIER;
	}
	if(!isdigit(c) && c != '.' && c != '(') 
		return c;
	i = 0;
	if(c == '(')
	{
		string[i] = '-';
		string[++i] = c = getch();
	}
	if(isdigit(c))
		while(isdigit(string[++i] = c = getch()));
	if(c == '.')
		while(isdigit(string[++i] = c = getch()));
	string[i] = '\0';
	if(c != EOF && c != ')')
		ungetch(c);
	return NUM;
}
