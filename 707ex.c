/* EX 7-7
 * Modify the pattern finding program of chapter 5 to take its input
 * from a set of named files or,if no files are named as arguments, from the 
 * standard input. Should the file name be printed when a matching line is found? Yes.
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define LINE_LIMIT 80
#define MAX_FILES 30
#define PATTERN_LIMIT 50

bool is_stdin = false;
FILE *files[MAX_FILES];
char *file_names[MAX_FILES];

FILE *file_opener(char *filename);
int read_line(FILE *file, char *line);
int pattern_match(char line[], char pattern[]);
int read_input(int limit, char *pattern);
int find_pattern(FILE *input_file, char *fname, char *pattern);

FILE *file_opener(char *filename)
{
	FILE *temp;
	if((temp = fopen(filename,"r")) == NULL) {
		fprintf(stderr,"failed to open %s\n",filename);
		exit(1);
	}
	else return temp;
}
int pattern_match(char line[], char pattern[])
{
	int i,j,k;
	for(i = 0; line[i] != '\0'; i++) {
		for(j = i, k = 0; line[j] == pattern[k]; j++,k++);
		if(k > 0 && pattern[k] == '\0')
			return k;
	}
	return 0;
}
int find_pattern(FILE *input_file, char *fname, char *pattern)
{
	char line[LINE_LIMIT];
	int line_count = 0;
	while(read_line(input_file,line)) {
		line_count++;
		if(pattern_match(line,pattern)) 
			fprintf(stdout,"%s : %2d : %s",fname,line_count,line);
	}
}
int read_input(int limit, char *pattern)
{
	int i;
	if(is_stdin)
		find_pattern(stdin,"STDIN",pattern);
	else
		for(i = 0; i < limit; i++)
			find_pattern(files[i],file_names[i],pattern);
}
int read_line(FILE *file, char *line)
{
	int i,c;
	for(i = 0; i < LINE_LIMIT && (c = getc(file)) != EOF && c != '\n'; i++)
		line[i] = c;
	if(c == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return i;
}
int main(int argc, char *argv[])
{
	int cfiles;
	char pattern[PATTERN_LIMIT];
	if(argc == 1) {
		fprintf(stderr,"Usage : %s [PATTERN] [FILES]\n",argv[0]);
		return 1;
	}
	else {
		fprintf(stdout,"Given pattern : %s\n",strncpy(pattern,argv[1],PATTERN_LIMIT));
		if(argc == 2) { 
			fprintf(stderr,"No files provided\nTaking input from stdin\n");
			is_stdin = true;
		}
		else if(argc > 2) {
			for(cfiles = 0; cfiles < argc-2; cfiles++) {
				file_names[cfiles] = (char *) malloc(sizeof(argv[cfiles+2]));
				strcpy(file_names[cfiles],argv[cfiles+2]);
			}
		}
	}
	int i;
	if(!is_stdin)
		for(i = 0; i < cfiles; i++)
			files[i] = file_opener(file_names[i]);
	read_input(cfiles,pattern);
}
