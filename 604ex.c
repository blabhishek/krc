/* EX 6-4 
 * Write a program that prints the distinct words in its input sorted into
 * decreasing order of frequency of occurence. Precede each word by its count.
 */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"mylib.h"

#define RESET "\x1B[0m"
#define RED "\x1B[31m"
#define N_SIZE (sizeof noises / sizeof(noises[5]))
#define MAXWORD 100 
#define VOIDCMP int (*)(const void*,const void*)

struct tree {
	char *word;
	int count;
	struct tree *left;
	struct tree *right;
};
typedef struct tree *NODE;

/* noise words */
const char *noises[] = {
	"a",  "and",  "as",  "but",  "he",  "her",  "him",  "in",  "is",  "it",  "no",  "not",  
	"of",  "or",  "she",  "that",  "the",  "their",  "they",  "to",  
}; 

char *str_dupli(char *copy); void free_twords(NODE node);
void print_counts(NODE array[],int limit);
int compare_count(const void *n1, const void *n2);
int tree_to_array(NODE node,NODE array[],int index);
NODE talloc(void);
NODE add_word(NODE node, char *string,size_t *wordcount);
int getword(char *word, int lim);
int isword(char *string);
// void sortlist(NODE *list,int limit);

int main(int argc, char *argv[])
{
	char word[MAXWORD];
	NODE root;
	NODE *warray;
	size_t wordcount = 0;

	while(getword(word,MAXWORD) != EOF)
		if(isword(word))
			root = add_word(root,word,&wordcount);
	if(!wordcount) {
		printf("error : intput is empty\n");
		exit(0);
	}
	warray = (NODE*) malloc(wordcount * sizeof(NODE));
	tree_to_array(root,warray,0);
//	sortlist(warray,wordcount);
//	qsort((void**)warray,wordcount,sizeof(NODE),compare_count);
	quick_sort((void**)warray,0,wordcount-1,compare_count);
	print_counts(warray,wordcount);
	free_twords(root);
	free(warray);
}
void print_counts(NODE array[],int limit)
{
	int i;
	for(i = 0; i < limit; i++)
		printf("%4d - %s\n",array[i]->count, array[i]->word);
}
/*
void sortlist(NODE *list,int limit)
{
	int gap, i,j;
	NODE temp;

	for(gap = limit/2;gap > 0;gap /= 2)
		for(i = gap; i < limit;i++)
			for(j = i - gap;j >= 0;j -= gap) {
				if((list[j]->count) >= (list[j+gap]->count))
					break;
				temp = list[j];
				list[j] = list[j+gap];
				list[j+gap] = temp;
			}
}
*/
void free_twords(NODE node)
{
	if(node == NULL)
		return;
	free_twords(node->left);
	free_twords(node->right);
	free(node->word);
	free(node);
}	

int compare_count(const void *n1, const void *n2) 
{
	return (((NODE) n2)->count) - (((NODE) n1)->count);
}

int tree_to_array(NODE node,NODE *array,int index)
{
	if(!node)
		return index;
	array[index++] = node;
	index =	tree_to_array(node->left,array,index);
	return	tree_to_array(node->right,array,index);
}

/* allocates memory for a new word */
NODE talloc(void)
{
	return (NODE) malloc(sizeof(struct tree));
}
/* duplicates string to store them in a safe place */
char *str_dupli(char *copy)
{
	char *word;
	if((word = (char*) malloc(strlen(copy)+1)) != NULL)
		strcpy(word,copy);
	else {
		printf("string_duplication : error : memory allocation failed\n");
		exit(0);
	}
	return word;
}
/* adds words into tree in dictionary order and its count */
NODE add_word(NODE node, char *string,size_t *wordcount)
{
	int flag;
	if(node == NULL) 
	{
		node = talloc();
		node->word = str_dupli(string);
		node->count = 1;
		(*wordcount)++;
		node->left = node->right = NULL;
	}
	else if((flag = strcmp(string,node->word)) == 0)
		node->count++;
	else if(flag < 0)
		node->left = add_word(node->left,string,wordcount);
	else
		node->right = add_word(node->right,string,wordcount);
	return node;
}
/* checks if words are execptions */
int isword(char *word)
{
	char string[MAXWORD];
	strcpy(string,word);
	to_lower(string);
	if(strlen(string) == 1)
		return 0;
	int low,high,mid;
	high = N_SIZE -1;
	low = 0;
	int flag;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if((flag = strcmp(string,noises[mid])) < 0)
			high = mid -1;
		else if(flag > 0)
			low = mid +1;
		else 
			return 0;
	}
	return 1;
}

/* reads characters that make up as words */
int getword(char *word, int lim)
{
	int c,getch(void);
	void ungetch(int);
	char *w = word;
	while(isspace(c = getch()));
	if(c != EOF) 
		*w++ = c; 
	if(!isalpha(c))
	{
		*w = '\0';
		return c;
	}
	for(; --lim > 0; w++)
		if(!isalpha(*w = getch()))
		{
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}
