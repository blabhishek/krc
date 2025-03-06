#include<stdio.h>
int count(void);
int main(void)
{
	printf("%d\n",count());
}
int count(void)
{
	int num = 0;
	int c;
	while((c = getchar()) != EOF)
		num++;
	return num;
}

