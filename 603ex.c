/* EX 6-3
 * Write a cross-referencer that prints a list of all words in a documents, and,
 * for wach word, a list of the line of the numbers on which it occurs.
 * Remove noise words like "the","and", and so on.
 */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define RESET "\x1B[0m"
#define RED "\x1B[31m"
#define MAX_OCC 10000
#define EX_SIZE (sizeof exceptions / sizeof(exceptions[0]))
#define MAXWORD 100

struct tword {
	int occurence[MAX_OCC];
	int index;
	char *word;
	struct tword *left;
	struct tword *right;
};
/* exceptions that occur frequently */
const char *exceptions[] = {
	"and", "And", "in", "In", "is", "Is", "its", 
	"or", "that", "the", "The" 
};

static int line_number = 1;

/* function prototypes */
void free_twords(struct tword *node);
int getword(char *, int);
int isword(char *);
struct tword *talloc(void);
char *str_dupli(char *);
void print_words(struct tword *);
struct tword *add_word(struct tword *, char *, int);

int main(int argc, char *argv[])
{
	char word[MAXWORD];
	struct tword *root;
	while(getword(word,MAXWORD) != EOF)
		if(isword(word))
			root = add_word(root,word,line_number);
	print_words(root);
	free_twords(root);
}
void free_twords(struct tword *node)
{
	if(node == NULL)
		return;
	free_twords(node->left);
	free_twords(node->right);
	free(node->word);
	free(node);
}	
/* prints words in alphabetic order */
void print_words(struct tword *node)
{
	if(node != NULL)
	{
		print_words(node->left);
		printf(RED"%s : "RESET,node->word);
		for(int i = 0; i < node->index; i++)
			printf("%d, ",node->occurence[i]);
		printf("\b\b\n");
		print_words(node->right);
	}
}
/* allocates memory for a new word */
struct tword *talloc(void)
{
	return (struct tword *) malloc(sizeof(struct tword));
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
/* adds words into tree in dictionary order with its numberline */
struct tword *add_word(struct tword *node, char *string, int nline)
{
	int flag;
	if(node == NULL) 
	{
		node = talloc();
		node->word = str_dupli(string);
		node->occurence[0] = nline;
		node->index = 1;
		node->left = node->right = NULL;
	}
 	else if((flag = strcmp(string,node->word)) == 0)
		node->occurence[node->index++] = nline;
	else if(flag < 0)
		node->left = add_word(node->left,string,nline);
	else
		node->right = add_word(node->right,string,nline);
	return node;
}
/* checks if words are execptions */
int isword(char *string)
{
	if(*++string == '\0')
		return 0;
	int low,high,mid;
	high = EX_SIZE -1;
	low = 0;
	int flag;
	while(low <= high)
	{ mid = (low + high) / 2;
		if((flag = strcmp(string,exceptions[mid])) < 0)
			high = mid -1;
		else if(flag > 0)
			low = mid +1;
		else
			return 0;
	}
	return 1;
}
/* reads characters the resemble make up as words */
int getword(char *word, int lim)
{
	int c,getch(void);
	void ungetch(int);
	char *w = word;
	while(isspace(c = getch()) && c != '\n');
	if(c == '\n')
		line_number++;
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
