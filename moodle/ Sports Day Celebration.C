#include<stdio.h>
int main()
    {
        int p,t,left;
        scanf("%d\n%d",&p,&t);
        if(t !=0){
            int s_team= p/t;
            left=p-(s_team*t);
            printf("%d\n%d",s_team,left);
    }
    
    return 0;
    }