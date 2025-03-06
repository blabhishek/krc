#ifndef CALC_H
#define CALC_H

#define NUM '0'
#include<string.h>
#define MAXVAL 100
#define IDENTIFIER 'i'
void alphabet(char string[]);
double peek(void);
void clear_stack(void);
void duplicate(void);
void swap_items(void);
void push(double num);
double pop(void);
int getop(char string[]);
void ungetch(int c);
int getch(void);

#endif
