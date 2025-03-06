#include<stdio.h>
int strcmp1(char s[],char t[]);
int main(void)
{
	char name1[] = "herlo";
	char name2[] = "hello";
	int c = strcmp1(name1,name2);
	printf("%d",c);
}
int strcmp1(char s[],char t[])
{
	int i;
	for(i = 0; s[i] == t[i]; i++)
	{
		if(s[i] == '\0')
			return 0;
	}
	return s[i] - t[i];
}
