// prints Farenheit to Celsius table 
#include<stdio.h>
#define STEP 10 
#define LOWER 0
#define UPPER 300

void main() 
{
    float cel,farhn;
    farhn = LOWER;
    printf("\t++++ Farenheit to Celsius Table ++++\n\n");
    printf("| \t +Farenheit \t | \t +Celsius+ \t |\n");

    while(farhn <= UPPER)
    {
        cel = (5.0 / 9.0) * (farhn-32.0) ;
        printf("| \t %6.1f \t | \t %6.2f \t | \n",farhn,cel);
        farhn += STEP;
    }
}
