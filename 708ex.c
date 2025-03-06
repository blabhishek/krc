/* EX 7-8
 * Write a program to print a set of files, starting each new one on a
 * new page, with a title and a running page count for each file.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_FILES 50
#define PAGE_HEIGHT 64
#define PAGE_WIDTH 72

char *file_names[MAX_FILES];
FILE *files[MAX_FILES];

FILE *file_opener(char *filename);
int arg_handler(int argc, char *argv[]);
int print_page(FILE *file,int npage, char *fname);
void print_file(FILE *file, char *filename);

FILE *file_opener(char *filename)
{
	FILE *temp;
	if((temp = fopen(filename,"r")) == NULL) {
		fprintf(stderr,"failed to open %s\n",filename);
		exit(1);
	}
	else return temp;
}
int print_page(FILE *file,int npage, char *fname)
{
	int i,j;
	int c;
	fprintf(stdout,"%s\t\t\t Page %d\n\n\n",fname,npage);
	for(i = 0; i < PAGE_HEIGHT; i++) {
		c = getc(file);
		for(j = 0; j < PAGE_WIDTH && c != EOF && c != '\n' ; j++) {
			putchar(c);
			c = getc(file);
		}
		putchar('\n');
	}
	fprintf(stdout,"\n\n\n\n");
	return c;
}
void print_file(FILE *file, char *filename)
{
	int page_count = 1;
	while(print_page(file,page_count,filename) != EOF)
		page_count++;
}
int arg_handler(int argc, char *argv[])
{
	int cfiles;
	if(argc == 1) {
		fprintf(stderr,"Usage : %s [FILES]\n",argv[0]);
		exit(1);
	}
	else {
		for(cfiles = 0; cfiles < argc-1 && cfiles < MAX_FILES; cfiles++) {
			if(access(argv[cfiles+1],F_OK | R_OK) != 0) {
				fprintf(stderr,"%s : failed read file\n",argv[cfiles+1]);
				exit(1);
			}
			file_names[cfiles] = (char *) malloc(sizeof(argv[cfiles+1]));
			strcpy(file_names[cfiles],argv[cfiles+1]);
		}
	}
	return cfiles;
}
int main(int argc, char *argv[])
{
	int nfiles = arg_handler(argc,argv);
	int i;
	FILE *file;
	for(i = 0; i < nfiles; i++) {
		files[i] = file_opener(file_names[i]);
		print_file(files[i],file_names[i]);
	}
	while(--i >= 0)
		fclose(files[i]);
}
