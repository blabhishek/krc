/* EX 5-7
 * Rewrite readlines to store lines in an array suppied by main,
 * rather than calling alloc to maintain storage. how much faster is the program.
 */
#include<time.h>
#include<stdio.h>
#include<string.h>
#define MAXLINES 5000
#define MAXLEN 1000
#define MAXSTORE 10000

char *lineptr[MAXLINES];

int readlines(char *lineptr[],int maxlines,char *line_store);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

int main(void)
{
	clock_t start,end;
	double cpu_time;
	start = clock();
	int nlines;
	char line_store[MAXSTORE];
	if((nlines = readlines(lineptr,MAXLINES,line_store)) >= 0)
	{
		qsort(lineptr,0,nlines-1);
		writelines(lineptr,nlines);
		end = clock();
		cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("\ntime taken - %f\n",cpu_time);
		return 0;
	}
	else
	{
		printf("ERROR : input is too big to sort\n");
		return 1;
	}
}
int getline_c(char[],int);

int readlines(char *lineptr[],int maxlines,char *line_store)
{
	int len,nlines;
	char *p,line[MAXLEN];
	nlines = 0;
	p = line_store + strlen(line_store);
	while((len = getline_c(line,MAXLEN)) > 0)
		if(nlines >= maxlines || (strlen(line_store) + len) > MAXSTORE)
			return -1;
		else
		{
			line[len-1] = '\0';
			strcpy(p,line);
			lineptr[nlines++] = p;
			p += len;
		}
	return nlines;
}
void writelines(char *lineptr[], int nlines)
{
	int i;
	for(i = 0; i < nlines; i++)
		printf("%s\n",lineptr[i]);
}
void qsort(char *v[],int left,int right)
{
	int i,last;
	void swap(char *v[],int i,int j);
	if(left >= right)
		return;
	swap(v,left,(left/right) /2);
	last = left;
	for(i = left+1; i <= right; i++)
		if(strcmp(v[i],v[left]) < 0)
			swap(v,++last,i);
	swap(v,left,last);
	qsort(v,left,last-1);
	qsort(v,last+1,right);
}
void swap(char *v[],int i,int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
