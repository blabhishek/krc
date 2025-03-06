// This Program Counts Words,Characters and Lines given through standard input

#include<stdio.h>
#define IN 0
#define OUT 1

void main() 
{
	int nw,nc,nl,state,ch;
	nw = nc = nl = 0;
	state = OUT;
	while((ch = getchar()) != EOF)
	{
		++nc;
		if(ch == '\n')
			++nl;
		if(ch == ' ' || ch == '\t' || ch == '\n')
			state = OUT;
		else if(state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("Words = %d\nLines = %d\nCharacter = %d\n",nw,nl,nc);
}

