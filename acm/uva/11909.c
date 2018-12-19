#include<stdio.h>
#include<math.h>
#define PI (2*acos(0))

int main()
{

    double l,w,h,th,a;
    while(scanf("%lf %lf %lf %lf",&l,&w,&h,&th)==4)
    {
        th*=PI/180;
        if(h*cos(th)>l*sin(th))
        {
        a=h-(.5*l*tan(th));
        printf("%.3lf mL\n",l*w*a);
        }
        else
        {
        a=.5*h*h*w*tan((PI/2)-th);
        printf("%.3lf mL\n",a);
        }
    }

    return 0;
}
