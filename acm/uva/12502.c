#include<stdio.h>

int main()
{
    double x,y,each,$,t,amount;
    scanf("%lf",&t);
    while(t--){
    scanf("%lf %lf %lf",&x,&y,&$);
    each=(x+y)/3;
    x=x-each;
    y=y-each;
    amount=x*$/(x+y);
    printf("%.0lf\n",amount);
    }
    return 0;
}
