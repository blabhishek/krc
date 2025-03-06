#include<stdio.h>
#define TAB 8
void entab(int m, int n)
{
	int nspace,nchar;
	int N;
	int c;
	nspace = nchar = 0;
	N = m;
	while((c = getchar()) != EOF)
	{
		if(c == ' ')
			++nspace;
		else
		{
			while(nspace >= N)
			{
				putchar('\t');
				nspace -= N;
			}
		}
	}
}
void detab(int m, int n)
{
	int ntabs,nchar;
	int c;
	int N = m;
	nchar = 0;
	while((c = getchar()) != EOF)
	{
		if(c == '\t')
		{
			while(nchar <= N)
			{
				putchar(' ');
				nchar++;
			}
			N += n;
		}
		else
			putchar(c);
		if(c == '\n')
			nchar = 0;
		nchar++;
	}
}
int main()
{
	detab(4,4);
}
