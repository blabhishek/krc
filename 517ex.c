/* EX 5-17
 * Add a field-handling capability, so sorting may be done in fields within lines,
 * each field sorted according to an indepentdent set of options.
 * (The index for this book was sorted with -df for
 * the index category and -n for the page numbers.)
 */
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#define MAXLINES 5000
#define TRUE 1
#define FALSE 0

int compare_strings_d(const void *v1,const void *v2);
int compare_strings(const void *v1,const void *v2);
int compare_strings_fold(const void *v1,const void *v2);
int compare_number(const void *s1,const void *s2);
void swap(void *v[],int i,int j);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

char *lineptr[MAXLINES];
int is_reverse = FALSE;
int fold = FALSE;
typedef int (*comparer_t)(const void *v1,const void *v2);

const comparer_t compare_func[] = 
{
	compare_strings,compare_strings_fold,compare_number,compare_strings_d
};
enum {
	DEFAULT,
	FOLD,
	NUMERIC,
	DIREC
};

int main(int argc, char *argv[])
{
	int nlines;
	int compare_type = DEFAULT;
	int c,i;
	i = 1;
	if(argc > 1)
	{
		while(argc-- > 1)
		{
			if(!strcmp(argv[i],"-r"))
				is_reverse = TRUE;
			else if(!strcmp(argv[i],"-n"))
				compare_type = NUMERIC;
			else if(!strcmp(argv[i],"-f"))
			{
				compare_type = FOLD;
				fold = TRUE;
			}
			else if(!strcmp(argv[i],"-d"))
				compare_type = DIREC;
			else
				printf("unkown option -%s\n",argv[i]);
			i++;
		}
	}
	comparer_t comp = compare_func[compare_type];
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
	return is_reverse ? -(v1 - v2) : v1 - v2;
}
int compare_strings(const void *v1,const void *v2)
{
	const char *s1 = *(const char**)v1;
	const char *s2 = *(const char**)v2;

	return is_reverse ? -(strcmp(s1,s2)) : strcmp(s1,s2);
}
int compare_strings_d(const void *v1,const void *v2)
{
	const char *s1 = *(const unsigned char**)v1;
	const char *s2 = *(const unsigned char**)v2;
	while(!isdigit(*s1) && !isalpha(*s1) && !isspace(*s1) && *s1)
		s1++;
	while(!isdigit(*s2) && !isalpha(*s2) && !isspace(*s2) && *s2)
		s2++;
	while(fold ? toupper(*s1) == toupper(*s2) : *s1 == *s2 && *s1)
	{
		if(!isdigit(*s1) && !isalpha(*s1) && !isspace(*s1) && *s1)
			s1++;
		else
			s1++;
		if(!isdigit(*s2) && !isalpha(*s2) && !isspace(*s2) && *s2)
			s2++;
		else
			s2++;
	}
	int result = fold ? toupper(*s1) - toupper(*s2) : *s1 - *s2;
	return is_reverse ? -(result) : result;
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
	int result = toupper(*s1) - toupper(*s2);
	return is_reverse ? -(result) : result ;
}
