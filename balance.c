#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    /* data */
    char ch;
    struct node *next;
}*top=NULL;

typedef struct node NODE;



void push(char x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->ch=x;
    nn->next=top;
    top=nn;
}

void pop(){
    NODE *temp=top;
    top=top->next;
    free(temp);
}

int isbal(char *s){
    size_t l=strlen(s);
    int i=0;
    while (1)
    {
        /* code */
        if(i==l) break;
        if(s[i]=='('||s[i]=='[' || s[i]=='{')
        push(s[i]);
        else if( top!=NULL && (top->ch=='(' && s[i]==')' || top->ch=='[' && s[i]==']' || top->ch == '{' && s[i]=='}'))
        pop();
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            return 0; // Unmatched closing symbol
        }
       // if(i==l) break;
        i++;
    }
    
        return top==NULL;
   
}

int main(){
    char s[100];
    scanf("%[^\n]s",s);
    if(isbal(s)) printf("balance");
    else printf("inbalanace");
}
