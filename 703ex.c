/* EX 7-3
 * Revise minprintf to handle more of the other facilities of printf
 */
#include<stdio.h>
#include<stdarg.h>

void minprintf(char *format, ...);
int main(void) 
{
	char name[] = "ok this is ok";
	int number = 90;
	char ok = ')';
	minprintf("%s %d %c",name,number,ok);
}
void minprintf(char *format, ...)
{
	va_list item;
	char *ptr, *string;
	int ivalue;
	double dvalue;
	char cvalue;
	unsigned uvalue;
	
	va_start(item,format);
	for(ptr = format; *ptr; ptr++) {
		if(*ptr != '%') {
			putchar(*ptr);
			continue;
		}
		switch(*++ptr) {
			case 'd' :
			case 'i' :
				ivalue = va_arg(item,int);
				printf("%d",ivalue);
				break;
			case 'f' :
				dvalue = va_arg(item,double);
				printf("%f",dvalue);
				break;
			case 's' :
				for(string = va_arg(item,char*); *string; string++)
					putchar(*string);
				break;
			case 'c' :
				ivalue = va_arg(item,int);
				putchar(ivalue);
				break;
			case 'u' :
				uvalue = va_arg(item,unsigned int);
				printf("%u",uvalue);
				break;
			case 'x' :
				uvalue = va_arg(item,unsigned int);
				printf("%x",uvalue);
				break;
			case 'X' :
				uvalue = va_arg(item,unsigned int);
				printf("%X",uvalue);
				break;
			case 'o' :
				uvalue = va_arg(item,unsigned int);
				printf("%o",uvalue);
				break;
			case 'e' :
				dvalue = va_arg(item,double);
				printf("%e",dvalue);
				break;
			case 'g' :
				dvalue = va_arg(item,double);
				printf("%g",dvalue);
				break;
			default :
				putchar(*ptr);
				break;
		}
	}
	va_end(item);
}
