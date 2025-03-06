/* EX 8-1
 * Rewrite the program cat from chaptet 7 using read, write,
 * open, and close instead of their standard library equivalents, 
 * Perform experiments to determine the relative speeds of the two versions.
 */

#include<stdio.h>
#include<unistd.h>
#include<sys/file.h>
#include<stdlib.h>

#define BUFFSIZE 500
typedef enum { false, true } bool;
void write_stdout(char *file);

int main(int argc, char *argv[])
{
	bool isstdin = false;
	if(argc == 1) 
		isstdin = true;
	int i;
	if(isstdin)
		write_stdout(NULL);
	else
		for(i = 1; i < argc; i++)
			write_stdout(argv[i]);
}

void write_stdout(char *file)
{
	char buff[BUFFSIZE];
	int n, fnum;
	if(file == NULL)
		fnum = 0;
	else if((fnum = open(file,O_RDONLY,0)) < 0) {
		fprintf(stderr,"failed to access %s\n",file);
		return;
	}
	while((n = read(fnum,buff,BUFFSIZE)) != 0)
		write(1,buff,n);
	close(fnum);
}
