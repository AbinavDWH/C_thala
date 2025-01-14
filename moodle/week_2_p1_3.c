#include<stdio.h>
int main(){
    int count;
    scanf("%d",&count);
    float price =3.49;
    float total_price = (price*count);
    printf("Regular price: %.2f",total_price);
    float dis_price=(total_price*0.6);
    printf("\nDiscount: %.2f",dis_price);
    float net_price = (total_price - dis_price);
    printf("\nTotal: %.2f",net_price);
    return 0;
}