#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STD, int n,*/
    size_t s =0,m=0,n=0;
    char* a=NULL;
    char *b=NULL;
    char *c=NULL;
    
      getline(&a, &s,stdin);
      getline(&b, &m,stdin);
        getline(&c, &n,stdin);
         a[strcspn(a, "\n")] = 0;

            puts(a);
            puts(b);
            puts(c);       
            free(a);
            free(b);
            free(c);
    return 0;
}