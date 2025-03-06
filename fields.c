#include<stdio.h>
struct fields {
	unsigned int is_ok : 3;
	unsigned int is_alright : 1;
	unsigned int is_here : 1;
} flags;
int main(void)
{
	flags.is_ok = 3;
	printf("%d\n",flags.is_ok);
}
