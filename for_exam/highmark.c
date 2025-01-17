#include<stdio.h>
#include<string.h>

struct table
{
    /* data */
    char name[20];
    int mark;
};



int main(){
    int n;
    scanf("%d",&n);
    struct table obj[n];
    for(int i=0;i<n;i++){
        char tmp[20];
        scanf("%[^,],%d",tmp,&obj[i].mark);
        strcpy(obj[i].name,tmp);
    }
    int big=obj[0].mark;
    for(int i=1;i<n;i++){
        if(big<obj[i].mark){
            big=obj[i].mark;
        }
    }
    for(int i=0;i<n;i++){
        if(big==obj[i].mark){
            puts(obj[i].name);
            break;
        }
    }
      
}