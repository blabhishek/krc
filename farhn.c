/* Prints Farenheit-Celsius table */
#include<stdio.h>
#define STEP 10 
#define LOWER 0
#define UPPER 300

void main() 
{
    float cel,farhn;
    farhn = LOWER;
    printf("++++ Farenheit to Celsius Table ++++\n\n");
    printf("|  Farenheit\t|  Celsius |\n");

    while(farhn <= UPPER)
    {
        cel = (5.0 / 9.0) * (farhn-32.0) ;
        printf("|   %5.1f   \t| %6.1f   | \n",farhn,cel);
        farhn += STEP;
    }
}
