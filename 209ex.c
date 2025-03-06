/* In two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x.
 * Explain why. Use this observation to write a faster version of bitcount.
 */

#include<stdio.h>
int bitcount(unsigned x);
void main()
{
	int x;
	printf("Enter an intger to count the 1-bits in it\n");
	scanf("%d",&x);
	printf("1-bits in the given integer is %d\n",bitcount(x));
}
int bitcount(unsigned x)
{
	int count = 0;
	while(x != 0)
	{
		x &= (x-1);
		count++;
	}
	return count;
}

