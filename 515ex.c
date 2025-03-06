/* EX 5-15
 * Add the option -f to fold upper and lower case together, so
 * that case distinctions are not made during sorting; for example,
 * a and A compare equal.
 */
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#define MAXLINES 5000

int compare_number_desc(const void *s1,const void *s2);
int compare_strings(const void *v1,const void *v2);
int compare_strings_desc(const void *v1,const void *v2);
int compare_strings_fold_desc(const void *v1,const void *v2);
int compare_strings_fold(const void *v1,const void *v2);
int compare_number(const void *s1,const void *s2);
void swap(void *v[],int i,int j);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

char *lineptr[MAXLINES];
typedef int (*comparer_t)(const void *v1,const void *v2);
const comparer_t compare_asc[] = 
{
	compare_strings,compare_strings_fold,compare_number
};
const comparer_t compare_desc[] = 
{
	compare_strings_desc,compare_strings_fold_desc,compare_number_desc
};
enum {
	DEFAULT,
	FOLD,
	NUMERIC
};

int main(int argc, char *argv[])
{
	int nlines;
	int is_reverse = 0;
	int compare_type = DEFAULT;
	int c,i;
	i = 1;
	if(argc > 1)
	{
		while(argc-- > 1)
		{
			if(!strcmp(argv[i],"-r"))
				is_reverse = 1;
			else if(!strcmp(argv[i],"-n"))
				compare_type = NUMERIC;
			else if(!strcmp(argv[i],"-f"))
				compare_type = FOLD;
			else
				printf("unkown option -%c\n",c);
			i++;
		}
	}
	comparer_t comp = (is_reverse ? compare_desc : compare_asc)[compare_type];
	if((nlines = readlines(lineptr,MAXLINES)) >= 0)
	{
		qsort(lineptr,nlines,sizeof *lineptr,comp);
		writelines(lineptr,nlines);
		return 0;
	}
	else
	{
		printf("ERROR : input is too big to sort\n");
		return 1;
	}
}
#define MAXLEN 1000
int getline_c(char[],int);
char *alloc(int);

int readlines(char *lineptr[],int maxlines)
{
	int len,nlines;
	char *p,line[MAXLEN];
	nlines = 0;
	while((len = getline_c(line,MAXLEN)) > 0)
		if(nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else
		{
			line[len-1] = '\0';
			strcpy(p,line);
			lineptr[nlines++] = p;
		}
	return nlines;
}
void writelines(char *lineptr[], int nlines)
{
	int i;
	for(i = 0; i < nlines; i++)
		printf("%s\n",lineptr[i]);
}
int compare_number(const void *s1,const void *s2)
{
	double v1 = atof(*(const unsigned char**)s1);
	double v2 = atof(*(const unsigned char**)s2);
	return v1 - v2;
}
int compare_number_desc(const void *s1,const void *s2)
{
	return compare_number(s2,s1);
}
int compare_strings(const void *v1,const void *v2)
{
	const char *s1 = *(const char**)v1;
	const char *s2 = *(const char**)v2;
	return strcmp(s1,s2);
}
int compare_strings_desc(const void *v1,const void *v2)
{
	return compare_strings(v2,v1);
}
int compare_strings_fold_desc(const void *v1,const void *v2)
{
	return compare_strings_fold(v2,v1);
}
int compare_strings_fold(const void *v1,const void *v2)
{
	const unsigned char *s1 = *(const unsigned char**)v1;
	const unsigned char *s2 = *(const unsigned char**)v2;
	while(toupper(*s1) == toupper(*s2) && *s1)
	{
		s1++;
		s2++;
	}
	return toupper(*s1) - toupper(*s2);
}
