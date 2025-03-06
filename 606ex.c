/* EX 6-6
 * Implement a simple version of the #define processor (i.e, no arguments) suitable 
 * for use with C programs, based on the routines of this section. You may also find
 * getch and ungetch helpful
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const char def_match[] = "#define";

#define MAXWORD 100
#define MAXDEF 30
#define HASHSIZE 101
struct def_list {
	struct def_list *next;
	char *name_def;
	char *definition;
};
static struct def_list *hashtab[HASHSIZE];

int undef(char *);
struct def_list *lookup(char *);
char *str_dupli(char *);
unsigned hash(char *);
struct def_list *install(char *, char *);
int isdef(char *);

int main(int argc, char *argv[])
{
	char filename[30];
	if(argc > 1)
		strcpy(filename,argv[1]);
	else {
		printf("usage : ./define file_name\n");
		exit(0);
	}
	FILE *intput;
	input = fopen(filename,"r");
	
	char string[MAXWORD];
	while(getword(word,MAXWORD) != EOF)
	{
		if(isdef(word))
			if(get_def(word,MAXDEF))

	}
}
int get_def(char *word, int limit)
{
	int c;
	char *p;
	p = word;
	while(isspace(c = getch()));
	if(isalpha(c))
		*p++ = c;
	else
		return 0;
	for(; --limit > 0; p++)
		if(!isalnum(*w = getch()) && *w != '_') {
			ungetch(*w);
			break
		}
	*w = '\0';
	return 1;
}
int isdef(char *def)
{
	int i;
	for(i = 0; def_match[i] != '\0' && *def == def_match[i]; i++,def++) ;
	return (def_match[i] == '\0') ? 1 : 0;
}
struct def_list *lookup(char *word)
{
	struct def_list *node;
	for(node = hashtab[hash(word)]; node != NULL; node = node->next)
		if(strcmp(word,node->name_def) == 0)
			return node;
	return NULL;
}
int undef(char *word)
{
	struct def_list *prev;
	struct def_list *curr;
	unsigned hashval = hash(word);
	for(prev = NULL,curr = hashtab[hashval]; curr != NULL; prev = curr, curr = curr->next) {
		if(strcmp(word,curr->name_def) == 0) {
			if(prev == NULL)
				hashtab[hashval] = curr->next;
			else 
				prev->next = curr->next;
			free(curr->name_def);
			free(curr->definition);
			free(curr);
			return 1;
		}
	}
	return 0;
}

struct def_list *install(char *word, char *meaning)
{
	struct def_list *node;
	unsigned hashval;

	if((node = lookup(word)) == NULL) {
		node = (struct def_list *) malloc(sizeof(*node));
		if(node == NULL || (node->name_def = str_dupli(word)) == NULL)
			return NULL;
		hashval = hash(word);
		node->next = hashtab[hashval];
		hashtab[hashval] = node;
	}
	else
		free((void*) node->definition);
	if((node->definition = str_dupli(meaning)) == NULL)
		return NULL;
}
unsigned hash(char *s)
{
	unsigned hashval;
	for(hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}
char *str_dupli(char *copy)
{
	char *word;
	if((word = (char*) malloc(strlen(copy)+1)) != NULL)
		strcpy(word,copy);
	return word;
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

/* main for test 

int main(int argc, char *argv[])
{
	char word[50];
	char def[60];
	int option;
	struct def_list *root;
	for(;;) {
		printf("1.insert word \n2.lookup word\n3.remove word\n");
		scanf("%d",&option);
		switch(option) {
			case 1:
				printf("Enter word :\n");
				scanf("%s",word);
				printf("Enter definition : \n");
				scanf("%s",def);
				root = install(word,def);
				break;
			case 2:
				printf("Enter word : ");
				scanf("%s",word);
				root = lookup(word);
				if(root != NULL)
					printf("%s - %s\n",root->name_def,root->definition);
				else
					printf("word not found\n");
				break;
			case 3:
				printf("Enter word : \n");
				scanf("%s",word);
				if(undef(word))
					printf("%s -- removed\n",word);
				else
					printf("given word is not found\n");
				break;
			default:
				puts("error : wrong option");
				exit(0);
		}
	}
}
*/
