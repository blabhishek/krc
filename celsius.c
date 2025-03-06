// prints Celsius to Farenheit table
#include<stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 10

void main()
{
	float farhn,celsius;
	int i;
	printf("\t++++ Celsius to Farenheit Table ++++\n\n");
	printf("|\t+Celsius+ \t|\t+Farenheit+\t|\n");
	for(celsius = 0; celsius <= UPPER; celsius += STEP)
	{
		farhn =  celsius * 1.8 + 32;
		printf("|\t %6.1f \t|\t %6.2f \t|\n",celsius,farhn);
	}
}



