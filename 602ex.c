/* EX 6-2
 * Write a program that reads a C program and prints in alphabetical order each
 * group of variable names that are identical in the first 6 characters, but
 * different somewhere thereafter. Don't count words within strings and comments. 
 * Make 6 a parameter that can be set from the command line.
 */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"mylib.h"

struct tnode {
	char *word;
	struct tnode *left;
	struct tnode *right;
};

#define MAXWORD 100
int ismatch(char[], char[]);
struct tnode *talloc(void);
struct tnode *addtree(struct tnode *,char *);
void treeprint(struct tnode*);
int getword(char *word, int lim);
struct tnode *talloc(void);
char *strdupli(char *);

int main(int argc, char *argv[])
{
	char match[10];
	char word[MAXWORD];
	if(argc > 1)
		strcpy(match,argv[1]);
	else {
		printf("usage : ./count_var wordtomatch\n");
		exit(0);
	}
	int i = 0;
	struct tnode *root;
	while(getword(word,MAXWORD) != EOF)
		if(ismatch(match,word))
			root = addtree(root,word);
	treeprint(root);
	return 0;
}
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;
	if(p == NULL)
	{
		p = talloc();
		p->word = strdupli(w);
		p->left = p->right = NULL;
	}
	else if((cond = strcmp(w,p->word)) == 0)
		;
	else if(cond < 0)
		p->left = addtree(p->left,w);
	else
		p->right = addtree(p->right,w);
	return p;
}
void treeprint(struct tnode *p)
{
	if(p != NULL)
	{
		treeprint(p->left);
		printf("- %s\n",p->word);
		treeprint(p->right);
	}
}
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}
char *strdupli(char *string)
{
	char *ptr;
	ptr = (char *) malloc(strlen(string)+1); /* extra 1 for '\0' */
	if(ptr != NULL)
		strcpy(ptr,string);
	return ptr;
}
int ismatch(char match[], char string[]) 
{
	int i;
	for(i = 0; string[i] != '\0' && match[i] != '\0' && match[i] == string[i]; i++);
	return (i >= 6) ? 1 : 0;
}
int getword(char *word, int lim)
{
	int c,getch(void);
	void ungetch(int);
	char *w = word;
	while(isspace(c = getch())) ;
	if(c == '/')
	{
		if((c = getch()) == '/')
			while((c = getch()) != '\n');
		else if(c == '*')
			while((c = getch()) != '*' && (c = getch()) != '/') ;
	}
	else if(c == '\"')
		while((c = getch()) != '\"');
	else if(c == '#')
		while((c = getch()) != '\n');
	if(c != EOF) *w++ = c; 
	if(!isalpha(c))
	{
		*w = '\0';
		return c;
	}
	for(; --lim > 0; w++)
		if(!isalnum(*w = getch()) && *w != '_')
		{
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}
