#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};
#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];
struct nlist *lookup(char *s);
char *str_dupli(char *);
unsigned hash(char *s);
struct nlist *install(char *name, char *defn);

int main(int argc, char *argv[])
{
	char word[50];
	char def[60];
	int option;
	struct nlist *root;
	for(;;) {
		printf("1.insert word \n2.lookup word\n");
		scanf("%d",&option);
		switch(option) {
			case 1:
				printf("Enter word :\n ");
				scanf("%s",word);
				printf("Enter def : \n");
				scanf("%s",def);
				root = install(word,def);
				break;
			case 2:
				printf("Enter word : ");
				scanf("%s",word);
				root = lookup(word);
				printf("%s - %s\n",root->name,root->defn);
				break;
			default:
				puts("error : wrong option");
				exit(0);
		}
	}
}

unsigned hash(char *s)
{
	unsigned hashval;
	for(hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}
struct nlist *lookup(char *s)
{
	struct nlist *np;
	for(np = hashtab[hash(s)]; np != NULL; np = np->next)
		if(strcmp(s,np->name) == 0)
			return np;
	return NULL;
}
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if((np = lookup(name)) == NULL) {
		np = (struct nlist *) malloc(sizeof(*np));
		if(np == NULL || (np->name = str_dupli(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else
		free((void*) np->defn);
	if((np->defn = str_dupli(defn)) == NULL)
		return NULL;
}
char *str_dupli(char *copy)
{
	char *word;
	if((word = (char*) malloc(strlen(copy)+1)) != NULL)
		strcpy(word,copy);
	return word;
}

