#include<stdio.h>
#include<unistd.h>
#define NALLOC 1024 

typedef long Align;

union header {
	struct {
		union header *nextp;
		unsigned size;
	} s;
	Align x;
};
typedef union header Header;
static Header base;
static Header *freep = NULL;

void *malloc_kr(unsigned nbytes);
static Header *morecore(unsigned);
void free_kr(void *free_mem);

int main(void)
{
	int *number = (int *) malloc_kr(sizeof(int));
	*number = 20;
	printf("%d\n",*number);
	free_kr(number);
}

void *malloc_kr(unsigned nbytes)
{
	Header *currp, *prevp;
	unsigned nunits;

	nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
	if((prevp = freep) == NULL) {
		base.s.nextp = freep = prevp = &base;
		base.s.size = 0;
	}
	for(currp = prevp -> s.nextp; ; prevp = currp, currp = currp -> s.nextp) {
		if(currp -> s.size >= nunits) {
			if(currp -> s.size == nunits) 
				prevp -> s.nextp = currp -> s.nextp;
			else {
				currp -> s.size -= nunits;
				currp += currp -> s.size;
				currp -> s.size = nunits;
			}
			freep = prevp;
			return (void *) (currp+1);
		}
		if(currp == freep) 
			if((currp = morecore(nunits)) == NULL)
				return NULL;
	}
}

static Header *morecore(unsigned nunits) 
{
	char *returnp;
	Header *newp;

	if(nunits < NALLOC)
		nunits = NALLOC;

	returnp = sbrk(nunits * sizeof(Header));
	if(returnp == (void *) - 1) 
		return NULL;

	newp = (Header *) returnp;
	newp -> s.size = nunits;
	free_kr((void *) (newp + 1));
	return freep;
}
void free_kr(void *free_mem)
{
	Header *insertp, *prevp;

	insertp = (Header *) free_mem - 1;
	for(prevp = freep; !(insertp > prevp && insertp < prevp -> s.nextp); prevp = prevp -> s.nextp)
		if(prevp >= prevp -> s.nextp && (insertp > prevp || insertp < prevp -> s.nextp))
			break;

	if(insertp + insertp -> s.size == prevp -> s.nextp) {
		insertp -> s.size += prevp -> s.nextp -> s.size;
		insertp -> s.nextp = prevp -> s.nextp -> s.nextp;
	}
	else 
		insertp -> s.nextp = prevp -> s.nextp;

	if(prevp + prevp -> s.size == insertp) {
		prevp -> s.size += insertp -> s.size;
		prevp -> s.nextp = insertp -> s.nextp;
	}
	else
		prevp -> s.nextp = insertp;

	freep = prevp;
}
