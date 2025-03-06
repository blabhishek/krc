#include<stdio.h>
void swap(int v[], int i, int j);

void qsort(int v[], int left, int right)
{
	int i,last;
	if(left >= right)
		return;
	swap(v,left,(left + right) / 2);
	last = left;
	for(i = left +1; i <= right; i++)
		if(v[i] < v[left])
			swap(v,++last,i);
	swap(v,left,last);
	qsort(v,left,last -1);
	qsort(v,last +1,right);
}
void swap(int v[], int i, int j)
{
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
int main(void)
{
	int v[] = {23,43,11,67,89,13,89,23,8,7,20,44};
	for(int i = 0; i < 12; i++)
		printf("%2d ",v[i]);
	printf("\n");
	qsort(v,0,11);
	for(int i = 0; i < 12; i++)
		printf("%2d ",v[i]);
	printf("\n");
}
/*
https://softwareengineering.stackexchange.com/questions/329725/how-does-krs-qsort-work

	The algorithm here is:

* Take the value in the middle of the array, and move it to the front (by swapping). 
  This value is the pivot.

* Loop through the rest of the array. Each time you see a value less than the pivot, 
  swap it to closer to the front of the array. Specifically we have an index (named last) that 
  keeps track of where the last lesser value was swapped to. 
  Each time we find a lesser value we increment it to find a spot to put that value.

* When you reach the end, the array consists of:
	* the pivot
	* all values less than the pivot
	* all values greater than or equal to the pivot

* Swap the pivot with the location of the last found lesser value.

At this point you know have a sub-array on either side of the pivot. 
To the left you have the values less than the pivot, 
to the right all values greater than or equal to the pivot. 
So you know that the pivot is in exactly the correct spot for the final sorted array. 
You also know that no values from either sub-array will need to swap with those on the other side. 

So you can now:

* sort the left sub-array with the same algorithm
* sort the right sub-array with the same algorithm.

Each time you recurse, you have smaller sub-arrays, so the next level of recursion is quicker. 
Also each time, you move one element into the correct position, before going deeper. 
Eventually you reach the point where there is only zero or one element in a sub-array, 
which of course means that sub-array is already sorted. What you end up with at any level is 
an element in the right spot, with a sorted sub-array of lesser values to the left, 
and a sorted sub-array of greater or equal values to the right, 
so you know the whole (sub-)array at that level is sorted.

*/
