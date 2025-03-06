#include "strex.h" 

char *strrev(char str[])
{
	int i; 
	char temp;
	int len = strlen(str)-1;
	for(i = 0; i != (len/2)+1; i++) {
		temp = str[i];
		str[i] = str[len - i];
		str[len - i] = temp;
	}
	return str;
}
char *int2str(int value)
{
	int num;
	char *str = (char*) malloc(128);
	char *p = str;
	int sign = value < 0 ? 1 : 0;
	if(sign)
		value = -value;

	while(value) {
		num = value % 10;
		*p = num + '0';
		value = value / 10;
		p++;
	}
	if(sign)
		*p++ = '-';
	*p = '\0';
	return strrev(str);
}
char *double2str(double value, int precision)
{
	long integer = value;
	double fraction = value - integer;
	char *str = (char*) malloc(sizeof(char) * (64 + precision));
	char *p = str;  
	short num;

	precision = (precision == 0) ? FRAC : precision;
	if(!integer)
		*p++ = '0';
	else {
		while(integer) {
			num = integer % 10;
			*p = num + '0';
			integer /= 10;
			p++;
		}
	}
	*p++ = '.';

	if(!fraction)
		*p = '0';
	else {
		while(precision) {
			num = fraction * 10;
			*p++ = num + '0';
			fraction *= 10;
			fraction -= num;
			precision--;
		}
	}
	*p = '\0';
	return str;
}

int scan_line(char line[],int maxline)
{
	int c,i;
	for(i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;
	if(c == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return i;
}
char *strsub(char str[],char *stamp)
{
	int len = strlen(str);
	int begin = 0;
	int end = len;
	int i;

	if(*stamp == ':')
		end = (*++stamp != '\0') ? atoi(stamp) : end;
	else if (isdigit(*stamp)) {
		begin = atoi(stamp);
		while(*stamp++ != ':');
		end = (*stamp != '\0') ? atoi(stamp) : end;
	}
	else {
		fprintf(stderr,"strsub() : wrong format stamp\n");
		return NULL;
	}
	if(begin < 0 || end < 0 || end > len) {
		fprintf(stderr,"strsub() : array index out of bound\n");
		return NULL;
	}

	char *substring = (char *) malloc(((end - begin) * sizeof(char))+1);
	char *ptr = substring;
	for(i = begin; i < end; i++)
		*ptr++ = str[i];
	*ptr = '\0';
	return substring;
}
