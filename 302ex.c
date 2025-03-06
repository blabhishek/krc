/* EX 3-2
 * Write a function escape(s,t) that converts characters like newline and tab into visible 
 * escape sequences like \n and \t as it copies the string t to s .
 * Use a switch. Write a function for the other direction as well, 
 * converting escape sequences into the real characters.
 */
#include<stdio.h>
#include<stdlib.h>
#define MAX 200
int option(void);
void unescape(char s[], char t[]);
void escape(char s[], char t[]);
	  
void main()
{
	int c;
	char s[MAX];
	char t[MAX];
	int i;
	int decide = option();
	printf("INPUT\n");
	for(i = 0; i < MAX -1 && (c = getchar()) != EOF; i++)
		t[i] = c;
	if(decide == 0)
		escape(s,t);
	else
		unescape(s,t);
	printf("%s",s);
}

void escape(char s[], char t[])
{
	int i,j;
	for(i = j = 0; t[j] != '\0'; i++,j++)
	{
		switch(t[j])
		{
			case '\t' :
				s[i++] = '\\';
				s[i] = 't';
				break;
			case '\n' :
				s[i++] = '\\';
				s[i] = 'n';
				break;
			default :
				s[i] = t[j];
				break;
		}
	}
	s[++i] = '\0';
}
void unescape(char s[], char t[])
{
	int j,i;
	for(i = j = 0; t[j] != '\0'; i++,j++)
	{
		switch(t[j])
		{
			case '\\' :
				switch(t[++j])
				{
					case 'n' :
						s[i] = '\n';
						break;
					case 't' :
						s[i] = '\t';
						break;
					case '\\' :
						s[i] = '\\';
						break;
				}
				break;
			default :
				s[i] = t[j];
				break;
		}
	}
	s[++i] = '\0';
}

int option(void)
{
	printf("Do you want to escape(e) or unescape(u) characters ?\n");
	char c = getchar();
	if(c == 'e' || c == 'E')
		return 0;
	else if(c == 'u' || c == 'U')
		return 1;
	else
	{
		printf("INVALID OPTION\n");
		exit(0);
	}
}

