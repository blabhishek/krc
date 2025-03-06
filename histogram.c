#include<stdio.h>
#define IN 1
#define OUT 0
#define MAX 10

void main()
{
	int i,c,state;
	int nc = 0;
	int ncw[MAX];
	state = OUT;
	for(i = 0; i < MAX; ++i)
		ncw[i] = 0;
	while((c = getchar()) != EOF)
	{
		if(c != ' ' &&  c != '\n' && c != '\t')
		{
			state = IN;
			++nc;
		}
		else {
			state = OUT;
			if(nc <= MAX)
				++ncw[nc -1];
			else
				++ncw[MAX -1];
			nc = 0;
		} 
	}
	int j;
	for(i = 0; i < MAX; ++i)
	{
		printf("word char %2d | ",i+1);
		for( j = 0; j < ncw[i]; ++j)
			printf("* ");
		printf("\n");
	}
}


