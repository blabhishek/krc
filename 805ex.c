#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<stdio.h>

#define MAX_PATH 1024
void fsize(char *);
void dirwalk(char *,void (*fcn)(char*));
char filetype(mode_t type);

int main(int argc, char **argv)
{
	if(argc == 1)
		fsize(".");
	else
		while(--argc > 0)
			fsize(*++argv);
	return 0;
}
char filetype(mode_t type)
{
	switch(type & S_IFMT) {
		case S_IFDIR :
			return 'd';
		case S_IFCHR :
			return 'c';
		case S_IFBLK :
			return 'b';
		case S_IFLNK:
			return 'l';
		case S_IFSOCK :
			return 's';
		case S_IFREG :
			return 'f';
		case S_IFIFO:
			return 'p';
		default :
			return '?';
	}
}
void fsize(char *name)
{
	struct stat stbuf;
	if(stat(name,&stbuf) == -1) {
		fprintf(stderr,"fsize: can't access %s\n",name);
		return;
	}
	if((stbuf.st_mode & S_IFMT) == S_IFDIR)
		dirwalk(name, fsize);
	printf("%8ld - %s - %c\n", stbuf.st_size, name,filetype(stbuf.st_mode));
}

void dirwalk(char *dir, void (*fcn)(char *))
{
	char name[MAX_PATH];
	struct dirent *dp;
	DIR *dfd;
	if((dfd = opendir(dir)) == NULL) {
		fprintf(stderr,"dirwalk: can't open %s\n",dir);
		return;
	}
	while((dp = readdir(dfd)) != NULL) {
			if(strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name,"..") == 0)
				continue;
			if(strlen(dir)+strlen(dp->d_name)+2 > sizeof(name))
				fprintf(stderr,"dirwalk: name %s/%s too long\n",dir,dp->d_name);
			else {
				sprintf(name,"%s/%s",dir,dp->d_name);
				(*fcn)(name);
			}
	}
	closedir(dfd);
}

