/* An implementation of getchar() using systemcall read() */

/* read() takes a file descriptor, buffer, num of bytes to be read,
 * and returns number of bytes read or returns 0 for end of file, or -1 
 * to indicate an error. */

#include<unistd.h>
#define BUFSIZ 1000
int getchar(void);
int main() 
{
	int c;
	while ((c = getchar()) != -1)
		write(1,&c,1);
}
int getchar(void) 
{
	static char buf[BUFSIZ];
	static char *bufp;
	static int n = 0;

	if( n == 0 ) {
		n = read(0,buf,sizeof buf);
		bufp = buf;
	}

	return (--n >= 0) ? (unsigned char) *bufp++ : -1;
}
