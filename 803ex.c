#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

#undef NULL
#define OPEN_MAX 20
#define BUFSIZE 2048
#define PERMS 0666
#define NULL 0
#define EOF (-1)

typedef struct filemode {
	unsigned int read : 1;
	unsigned int write : 1;
	unsigned int eof : 1;
	unsigned int err : 1;
	unsigned int unbuf : 1;
} FILEMODES;

typedef struct fileinfo {
	int count;
	char *ptr;
	char *buff;
	FILEMODES flag;
	int fd;
} MFILE; 

#define stdin (&_iof[0])
#define stdout (&_iof[1])
#define stderr (&_iof[2])

#define feof(p) ((p)->flag.eof)
#define ferror(p) ((p)->flag.err)
#define fileno(p) ((p)->fd)
#define getchar() getc(stdin)
#define putchar(c) putc((c),stdout)

#define getc(p) (--(p)->count >= 0 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(c,p) (--(p)->count >= 0 ? *(p)->ptr++ = (c) : _flushbuf((c),p))

MFILE _iof[OPEN_MAX] = {
	{ 0, (char*) 0, (char *) 0, { 1,0,0,0,0 }, 0},
	{ 0, (char*) 0, (char *) 0, { 0,1,0,0,0 }, 1},
	{ 0, (char*) 0, (char *) 0, { 0,1,0,0,1 }, 2}
};

MFILE* file_open(char *name, char *mode);
int _flushbuf(int c, MFILE *fp);
int _fillbuf(MFILE *fp);
int _fflush(MFILE *fp);

int _flushbuf(int c, MFILE *fp)
{
	int nwrite, bufsize;
	unsigned char uc = c;
	if(!fp->flag.write && fp->flag.err && fp->flag.eof)
		return EOF;
	if(fp->buff == NULL && !fp->flag.unbuf) {
		if((fp->buff = (char*) malloc(BUFSIZE)) != NULL) {
			fp->ptr = fp->buff;
			fp->count = BUFSIZE -1;
		}
		else
			fp->flag.unbuf = 1;
	}
	if(fp->flag.unbuf) {
		fp->ptr = fp->buff = NULL;
		fp->count = 0;
		if(c == EOF)
			return EOF;
		nwrite = write(fp->fd, &uc, 1);
		bufsize = 1;
	}
	else {
		if(c != EOF)
			*(fp)->ptr++ = uc;
		bufsize = (int) (fp->ptr - fp->buff);
		nwrite = write(fp->fd, fp->buff, bufsize);
		fp->ptr = fp-> buff;
		fp->count = BUFSIZE - 1;
	}
	if(nwrite == bufsize)
		return c;
	else {
		fp->flag.err = 1;
		return EOF;
	}
}

int _fillbuf(MFILE *fp)
{
	int bufsize;
	if(!fp->flag.read && fp->flag.eof && fp->flag.err)
		return EOF;
	bufsize = (fp->flag.unbuf) ? 1 : BUFSIZE;
	if(fp->buff == NULL)
		if((fp->buff = (char*) malloc(bufsize)) == NULL)
			return EOF;
	fp->ptr = fp->buff;
	fp->count = read(fp->fd, fp->ptr, bufsize);
	if(--fp->count < 0) {
		if(fp-> count == -1)
			fp-> flag.eof = 1;
		else
			fp-> flag.err = 1;
		fp->count = 0;
		return EOF;
	}
	return (unsigned char) *fp->ptr++;
}
int _fflush(MFILE *fp)
{
	int bufsize = (int) (fp->ptr - fp->buff);
	fp->count = 0;
	if(fp->flag.read) 
		return 0;
	if(bufsize > 0) 
		write(fp->fd, fp->buff, bufsize);
	return 0;
}
int _fclose(MFILE *fp)
{
	if(fp == NULL)
		return EOF;
	fp->count = 0;
	if(fp -> buff != NULL)
		free(fp->buff);
	fp->buff = fp->ptr = NULL;
	if(fp->fd < 0)
		return EOF;
	return close(fp->fd);
}

MFILE* file_open(char *name,char *mode)
{
	MFILE *fp;
	int fd;

	if(*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;
	for(fp = _iof; fp < _iof + OPEN_MAX; fp++)
		if(!fp -> flag.read && !fp ->flag.write)
				break;
	if(fp >= _iof + OPEN_MAX)
		return NULL;
	if(*mode == 'w')
		fd = creat(name, PERMS);
	else if(*mode == 'a') {
		if((fd = open(name, O_WRONLY, 0)) == -1)
			fd = creat(name, PERMS);
		lseek(fd, 0L, 2);
	} else
		fd = open(name, O_RDONLY, 0);
	if(fd == -1)
		return NULL;
	fp -> fd = fd;
	fp -> count = 0;
	fp -> buff = NULL;
	if(*mode == 'r')
		fp -> flag.read = 1;
	else 
		fp -> flag.write = 1;
	return fp;
}

int main(void)
{
	int i = 1;
	while(++i > 0) {
		putchar('0');
		putchar('\r');
		_fflush(stdout);
	}
}
