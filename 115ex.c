/* EX 1-15
 * Rewrite the temperature conversion program if section1.2 to use a function for conversion
 */

#include<stdlib.h>
#include<stdio.h>
float FtoC(float);
float CtoF(float);
void display(char);

void main()
{
	char option;
	printf("Press f(F) -Convert Farenheit to Celsius \n");
	printf("Press c(C) -Convert Celsius to Frenheit \n--> ");
	scanf("%c",&option);
	display(option);
}
void display(char option)
{
	float farhn,cel;
	if(option == 'f' || option == 'F')
	{
		printf("Farenheit : ");
		scanf("%f",&farhn);
		printf("Celsius = %.2f \n",FtoC(farhn));
	}
	else if(option == 'c' || option == 'C')
	{
		printf("Celsius: ");
		scanf("%f",&farhn);
		printf("Farenheit = %.2f \n",CtoF(farhn));
	}
	else 
		printf("Wrong choice\n");
	exit(0);
}
// converting functions
float FtoC(float farhn) {
	return ((5.0 / 9.0) * (farhn - 32.0));
}
float CtoF(float cel) {
	return (cel * 1.8 + 32);
}

