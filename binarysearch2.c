#include<stdio.h>
#define MAX 50
int binarysearch(int item, int array[], int size)
{
	int low,high,mid;
	low = 0;
	high = size -1;
	while(low < high)
	{
		mid = (low + high) / 2;
		if(item <=array[mid])
			high = mid;
		else 
			low = mid + 1;
	}
	return (item == array[low]) ? low : -1;
}
void main(void)
{
	int array[MAX];
	int size;
	int item;
	int i;
	printf("How many elements do you want to store int the array\n");
	scanf("%d",&size);

	printf("Enter %d elements\n",size);
	for(i = 0; i < size; ++i)
		scanf("%d",&array[i]);
	printf("Enter an element to search in the array\n");
	scanf("%d",&item);

	int result = binarysearch(item,array,size);
	if(result == -1)
		printf("The item is not found\n");
	else
		printf("The item is found at position %d\n",result+1);
}
		

