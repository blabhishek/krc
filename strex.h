#ifndef STREX_H 
#define STREX_H  1

#define FRAC 10
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int scan_line(char [],int);
char *strsub(char [],char*);
char *strrev(char []);
char *int2str(int value);
char *double2str(double value, int precision);

#endif

