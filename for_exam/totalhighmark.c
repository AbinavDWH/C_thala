#include<stdio.h>
#include<string.h>

struct markList
{
    /* data */
    char name[20];
    int m1,m2,m3;
    float avg;

};

int main(){
    int n;
    scanf("%d",&n);
    struct markList s[n];
    for(int i=0;i<n;i++){
        char tmp[20];
        scanf("%[^:]:%d:%d:%d",tmp,&s[i].m1,&s[i].m2,&s[i].m3);
        strcpy(s[i].name,tmp);
        s[i].avg=(float)(s[i].m1+s[i].m2+s[i].m3)/3;
        }
    float big=s[0].avg;
    for(int i=1;i<n;i++){
        if(big<s[i].avg)
        big =s[i].avg;
    }
    for(int i=0;i<n;i++){
        if(big==s[i].avg){
            puts(s[i].name);
            break;
        }
    }
}
