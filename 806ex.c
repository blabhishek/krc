/*EX806
 * The standard library function calloc(n,size) returns a pointer to n objects
 * of size 'size', with the storage initialized to zero. Write calloc, by calling
 * malloc or by modifying it.
 */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
void *n_calloc(size_t nunit, size_t unitsiz);
void set_zero(void *dest, size_t len)
{
	unsigned char *p = dest;
	while (len-- > 0)
		*p++ = 0;
}
void *n_calloc(size_t nunit, size_t unitsiz)
{
	void *p;
	if (nunit == 0 || unitsiz == 0)
		return 0;
	p = malloc(nunit * unitsiz);
	if (p) 
		set_zero(p, nunit * unitsiz);
	return p;
}
int main(int argc, char *argv[])
{
	int *nums = (int*) n_calloc(2, sizeof(int));
	*nums = 8;
	*(nums+1) = 10;
	printf("%d - %d\nsize = %d\n", *nums, *(nums+1), sizeof(nums));
	free(nums);
	return 0;
}
