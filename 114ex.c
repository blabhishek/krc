/* EX 1-14 
 * Write a program to print a histogram of the frequencies of
 * different characters in its input
 */


#include<stdio.h>
void main()
{
	int c,i,j,nc;
	nc = '~' - ' ';
	int ncount[nc];
	// initialises frequencies to 0
	for(i = 0; i < nc; ++i)
		ncount[i] = 0;
	// takes input and iterates frequencies of characters
	while((c = getchar()) != EOF)
		++ncount[c-' '];
	// prints the histogram
	for(i = 0; i < nc; ++i)
	{
		if(ncount[i] != 0)
		{
			printf(" %c : ",i + ' ');
			for(j = 0; j < ncount[i]; ++j)
				printf("* ");
			printf("\n");
		}
	}
}


