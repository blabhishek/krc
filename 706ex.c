/* EX 7-6
 * Write a program to compare two files, printing the first 
 * line where they differ.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LINE 100

int isdiff_line(char *line1, char *line2);
int get_line(char *line, FILE *file, int* count);

int main(int argc, char *argv[])
{
	FILE *file1,*file2;
	if(argc < 3) {
		fprintf(stderr,"%s : pass two files\n",argv[0]);
		fprintf(stderr,"Usage : comp file1 file2\n");
		exit(1);
	}
	else {
		if((file1 = fopen(argv[1],"r")) == NULL)
			fprintf(stderr,"%s : failed to open %s\n",argv[0],argv[1]);
		if((file2 = fopen(argv[2],"r")) == NULL)
			fprintf(stderr,"%s : failed to open %s\n",argv[0],argv[2]);
		if(file1 == NULL || file2 == NULL)
			exit(1);
	}
	char line1[MAX_LINE],line2[MAX_LINE];
	int lcount1 = 0, lcount2 = 0;
	int flag = 1;	

	while(flag) {
		get_line(line1,file1,&lcount1);
		get_line(line2,file2,&lcount2);
		flag = isdiff_line(line1,line2);
		if(feof(file1) || feof(file2)) {
			flag = 0;
			break;
		}
	}
	printf("%d - %d\n",feof(file1),feof(file2));
	if(!flag) {
		printf("%s - %d : %s\n",argv[1],lcount1,line1);
		printf("%s - %d : %s\n",argv[2],lcount2,line2);
	}
	else {
		printf("there was no difference between two files\n");
	}
	fclose(file1);
	fclose(file2);
}
int get_line(char *line, FILE *file, int *count)
{
	int i,c;
	for(i = 0; i < MAX_LINE && (c = getc(file)) != EOF && c != '\n'; i++)
		line[i] = c;
	if(i == 0 && c == EOF)
		return 0;
	if(c == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	*count += 1 ;
	return i;
}
int isdiff_line(char *line1, char *line2)
{
	while(*line1 != '\0' && *line2 != '\0' && *line1++ == *line2++);
	return (*line1 == '\0' && *line2 == '\0') ? 1 : 0;
}
