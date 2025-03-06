#include<stdio.h>
char* alloc(int n);
void afree(char* p);

int main(void)
{
	char* point = alloc(20);
	point = "hello";
	printf("%s",point);
	point = alloc(20);
	point = "ok";
	printf("%s",point);
	return 0;
}
