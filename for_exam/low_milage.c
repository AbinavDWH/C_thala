#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct low_milage
{
    char name[20];
    int milage;
};
 
 typedef struct low_milage class;

// int compare(const void *a,const void *b){
//     return *(int *)a-*(int *)b;
// }

int main(){
    int n;
    scanf("%d",&n);
    class obj[n];
    for(int i=0;i<n;i++){
        char tmp[20];
        scanf("%[^@]@%d",tmp,&obj[i].milage);
        strcpy(obj[i].name,tmp);
    }
    int small=obj[0].milage;
    for(int i=1;i<n;i++){
        if(small>obj[i].milage){
            small=obj[i].milage;
        }
    }
    for(int i=0;i<n;i++){
        if(obj[i].milage==small){
            printf("%s\n",obj[i].name);}
    }
}