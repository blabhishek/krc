// counts number of characters given through input
#include<stdio.h>
void main() {
    int nc;
    for(nc = 0; getchar() != EOF; ++nc);
    printf("%d\n",nc);
}


