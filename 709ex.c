/* EX 7-9
 * Functions like isupper can be implemented to save space or to save
 * time. Explore both possibilities
 */

/* There are several ways to implement isupper either to save
 * time or space. 
 */

/* creating a macro of the function isupper saves both time and space,
 * but it fails in locales other than ANSI.
 */
#include<stdio.h>
#define upper_macro(x) (x >= 'A' && x <= 'Z') ? 1 : 0 
int ex_isupper(int c);
int main(void)
{
	printf("%d",upper_macro('a'));

}
int ex_isupper(int c)
{
	return c;
}


