/* EX 5-14
 * Modify sort program to handle a -r flag, which indicates sorting in reverse(decreasing) order.
 * Be sure that -r works with -n.
 */
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAXLINES 5000
#define TRUE -1
#define FALSE 1

char *lineptr[MAXLINES];

void swap(void *v[],int i,int j);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort_c(void *lineptr[], int left, int right, int (*comp)(void *, void *),int reverse);
int numcmp(char *,char *);

int main(int argc, char *argv[])
{
	int nlines;
	int numeric = 0;
	int reverse = FALSE;
	int c,i;
	i = 1;
	if(argc > 1)
	{
		while(argc-- > 1)
		{
			c = argv[i][1];
			switch(c)
			{
				case 'r' :
					reverse = TRUE;
					break;
				case 'n' :
					numeric = 1;
				default :
					printf("unkown option -%c\n",c);
					break;
			}
			i++;
		}
	}
	if((nlines = readlines(lineptr,MAXLINES)) >= 0)
	{
		qsort_c((void **)lineptr,0,nlines-1,(int (*)(void *,void *))(numeric ? numcmp : strcmp),reverse);
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
void qsort_c(void *v[],int left,int right,int (*comp)(void *,void *),int order)
{
	int i,last;
	void swap(void *v[],int i,int j);
	if(left >= right)
		return;
//	swap(v,left,(left/right) /2);
	last = left;
	for(i = left+1; i <= right; i++)
		if(order * (*comp)(v[i],v[left]) < 0)
			swap(v,++last,i);
	swap(v,left,last);
	qsort_c(v,left,last-1,comp,order);
	qsort_c(v,last+1,right,comp,order);
}
int numcmp(char *s1,char *s2)
{
	double v1,v2;
	v1 = atof(s1);
	v2 = atof(s2);
	if(v1 < v2)
		return -1;
	else if(v1 > v2)
		return 1;
	else 
		return 0;
}
void swap(void *v[],int i,int j)
{
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
