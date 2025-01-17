#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

/**
 * Counts the occurrences of a character in a string, ignoring whitespace.
 *
 * @param str The input string.
 * @param char_to_count The character to count.
 * @return The number of occurrences of the character.
 */
int count_char(const char *str, char char_to_count) {
    int count = 0;
    while (*str) {
        if (*str == char_to_count) {
            count++;
        }
        str++;
    }
    return count;
}

int main(){
    char *s=NULL;
    size_t sz=0;
    int sum=0;
    getline(&s,&sz,stdin);
    char *a;
    a=strtok(s," ");
    while (a!=NULL)
    {
        /* code */
        sum+=atoi(a);
        a=strtok(NULL," ");
    }
    printf("%d",sum);
  
   // puts(s);
}