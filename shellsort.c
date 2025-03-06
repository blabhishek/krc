#include<stdio.h>
#include<stdlib.h>
#define MAX 50
void shellsort(int array[],int size);

void main(void)
{
	int array[MAX];
	short size,i;
	puts("Enter the size of Array :");
	scanf("%d",&size);
	printf("Enter %d elements\n",size);
	for(i = 0; i < size; i++)
		scanf("%d",&array[i]);
	shellsort(array,size);
	printf("The sorted elements are\n");
	for(i = 0; i < size; i++)
		printf("%d\n",array[i]);
}
void shellsort(int array[], int size)
{
	int i,j,temp,gap;

	for(gap = size/2; gap > 0; gap /= 2)
		for(i = gap; i < size; i++)
			for(j = i - gap; j >= 0 && array[j] > array[j+gap]; j -= gap)
			{
				temp = array[j];
				array[j] = array[j+gap];
				array[j+gap] = temp;
			}
}

