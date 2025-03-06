/* EX 7-4
 * Write a private version of scanf analogous to minprintf from the previous section
 */
#include<stdio.h>
#include<stdarg.h>
#define TRUE 1 
#define FALSE 0

void minscanf(char *format, ...);

int main(void) 
{
	int num;
	float percent;
	char *string;
	unsigned int unsign;
	minscanf("%d%f%s%u",&num,&percent,&unsign);
	printf("i = %d\n",num);
	printf("f = %f\n",percent);
	printf("s = %s\n",string);
	printf("u = %u\n",unsign);
}
void minscanf(char *format, ...) 
{
	va_list items;
	char *ptr;
	int valid = TRUE;
	int *ivalue;
	float *fvalue;
	char *sval;
	unsigned int *uvalue;
	
	va_start(items,format);

	for(ptr = format; *ptr; ptr++) {
		if(*ptr != '%') {
			if(*ptr == getchar())
				valid = TRUE;
			else
				valid = FALSE;
			continue;
		}
		switch(*++ptr) {
			case 'i' :
			case 'd' :
				ivalue = va_arg(items,int*);
				scanf("%d",ivalue);
				break;
			case 'f' :
				fvalue = va_arg(items,float*);
				scanf("%f",fvalue);
				break;
			case 's' :
				sval = va_arg(items,char*);
				scanf("%s",sval);
				break;
			case 'o' :
				ivalue = va_arg(items,int*);
				scanf("%o",ivalue);
				break;
			case 'x' :
				ivalue = va_arg(items,int*);
				scanf("%x",ivalue);
				break;
			case 'u' :
				uvalue = va_arg(items,unsigned int*);
				scanf("%u",uvalue);
				break;
		}
	}
	if(valid == FALSE)
		fputs("Invalid intput Format\n",stderr);
	va_end(items);
}
