/* EX 2-1
 * Write a program to determine the ranges of char,int,short and long
 * variables, both signed and unsigned, by printing appropriate values
 * from standard headers and by direct computation. Harder if you compute them 
 * : determine the ranges of various floating point type.
 */

#include<stdio.h>
#include<limits.h>
#include<float.h>
void main(void)
{
	/* SIGNED INTEGERS */
	printf("INT MAX:	%d\n",INT_MAX);
	printf("INT MIN:	%d\n",INT_MIN);
	printf("LONG MAX:	%ld\n",LONG_MAX);
	printf("LONG MIN:	%ld\n",LONG_MIN);
	printf("CHAR MIN:	%d\n",CHAR_MIN);
	printf("CHAR MIN:	%d\n",CHAR_MAX);

	/* UNSIGNED INTEGERS */
	printf("UNSIGNED INT MAX:	%u\n",UINT_MAX);
	printf("UNSIGNED SHORT MAX:	%d\n",USHRT_MAX);
	printf("UNSIGNED LONG MAX:	%u\n",ULONG_MAX);
	
	/* FLOAT & DOUBLE TYPES */
	printf("FLOAT MIN:	%e\n", FLT_MIN);
	printf("FLOAT MAX:	%e\n", FLT_MAX);
	printf("DOUBLE MIN:	%e\n", DBL_MIN);
	printf("DOUBLE MAX:	%e\n", DBL_MAX);
}
