#include<stdio.h>
//#define PI acos(-1)
int main()
{
    double a,x,y,lol,PI=acos(-1);
    //double z;
    lol=( 1 - cos(PI/6) - (PI/6) + (cos(PI/6))/2 );
    PI/=4;
    while(scanf("%lf",&a)==1)
    {
        a=a*a;
        x=a*lol;
        y=a - PI*a - 2*x;
        x*=4;
        y*=4;
        //z=a - x - y;
        //printf("%.3lf %.3lf %.3lf\n",z,y,x);
        printf("%.3lf %.3lf %.3lf\n",a-x-y,y,x);
    }
    return 0;
}
