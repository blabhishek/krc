/* EX 5-11
 * Modify the programs entab and detab to accept a list of tab stops as arguments.
 * Use the default tab settings if there are no arguments.
 */
#include<stdio.h>
#include<stdlib.h>
#define TAB 8
int entab(int argc,char *argv[]);
int detab(int argc,char *argv[]);

int main(int argc,char* argv[])
{
	entab(argc,argv);
}
int entab(int argc,char *argv[])
{
	int c,nchar,nspace;
	nspace = nchar = 0;
	int tabstops[30];
	int i;
	tabstops[0] = 0;
	if(argc >= 1)
	{
		for(i = 0; i < 30; i++)
			tabstops[i] += TAB;
	}
	else
		for(i = 0; i < argc-1; i++)
			tabstops[i] = atoi(*++argv);
	i = 0;
	while((c = getchar()) != EOF)
	{
		if(c == ' ')
			++nspace;
		else
		{
			while(nspace >= tabstops[i] - nchar)
			{
				putchar('\t');
				nspace -= tabstops[i++];
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
int detab(int argc,char *argv[])
{
	int c,i;
	int charcount = 0;
	int tabstops[30];
	tabstops[0] = 0;
	if(argc >= 1)
		for(i = 0; i < 30; i++)
			tabstops[i] += TAB;
	else
		for(i = 0; i < argc-1; i++)
			tabstops[i] = atoi(*++argv);
	i = 0;
	while((c = getchar()) != EOF)
	{
		if(c == '\t')
		{
			for(int j = 0; j < (tabstops[i] - (charcount % tabstops[i])); j++)
				putchar(' ');
			i++;
		}
		else
		{
			putchar(c);
			charcount++;
		}
		if(c == '\n')
			charcount = 0;
	}
}
