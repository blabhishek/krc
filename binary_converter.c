/* Program to convert Decimal digits to Binary */
#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int binaryconverter(int decimal,char binary[]);
int main(int argc, char *argv[])
{
	int num;
	char binary[MAX];
	if(argc < 2) {
		printf("usage : ./binary_converter number\n");
		exit(0);
	}
	num = atoi(argv[1]);
	int len = binaryconverter(num,binary);
	for(int j = len-1; j >= 0; j--)
		putchar(binary[j]);
}
int binaryconverter(int decimal,char binary[])
{
	int bin;
	int i;
	for(i = 0 ; decimal > 0; i++)
	{
		bin = decimal % 2;
		if(!bin)
			binary[i] = '0';
		else
			binary[i] = '1';
		decimal = decimal / 2;
	}
	binary[i] = '\0';
	return i;
}
			


	
