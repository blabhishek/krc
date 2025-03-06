#include<stdio.h>
#define swap(t,x,y) t temp; temp = x; x = y; y = temp;
int main(void)
{
	int n1 = 1;
	int n2 = 3;
	swap(int,n1,n2);
	printf("n1 = %d | n2 = %d",n1,n2);
}
