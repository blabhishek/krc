#include<stdio.h>
int bitcount(unsigned int x);
void main()
{
	printf("%d",bitcount(4));
}
int bitcount(unsigned int x) {
	int nb = 0;
	while (x != 0) {
		x &= x-1;
		nb++;
	}
	return nb;
}
