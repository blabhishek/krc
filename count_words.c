#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "mylib.h"
struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

#define MAXWORD 100
char *strdupli(char *string);
struct tnode *talloc(void);
struct tnode *addtree(struct tnode *,char *);
void treeprint(struct tnode*);
int getword(char *word, int lim);
struct tnode *talloc(void);
char *strdupli(char *);

int main(void)
{
	struct tnode *root;
	char word[MAXWORD];
	root = NULL;
	while(getword(word,MAXWORD) != EOF)
		if(isalpha(word[0]))
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
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if((cond = strcmp(w,p->word)) == 0)
		p->count++;
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
		printf("%4d - %s\n",p->count,p->word);
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
	else if(c == '"')
		while((c = getch()) != '"');
	else if(c == '#')
		while((c = getch()) != '\n');
	if(c != EOF)
		*w++ = c;
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
