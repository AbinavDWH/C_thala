#include<stdio.h>
#include<math.h>
int main(){
    float a,b,c;
    double roots[2];
    printf("Enter a,b,c:");
    scanf("%f %f %f",&a,&b,&c);
    double dis = pow((double)b,2)-(4*a*c); 
    if(dis<0){
        roots[1]=roots[0]=sqrt(-dis)/(2*a);
        printf("the roots are %f+%lfi and %f-%lfi",-b/(2*a),roots[0],-b/(2*a),roots[1]);
        }
    else if(dis>0){
        roots[0]=(-b+sqrt(dis))/(a*2);
        roots[1]=(-b-sqrt(dis))/(2*a);
        printf("the roots are %lf and %lf",roots[0],roots[1]);
    }
    else{
        roots[1]=roots[0]=(-b)/(2*a);
        printf("the roots are %lf and %lf",roots[0],roots[1]);
    }
    
}