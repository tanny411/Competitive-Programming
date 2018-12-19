#include<stdio.h>
#include<math.h>

int main()
{
    double PI=acos(-1),D,V,frac=1.0/3.0;
    while(scanf("%lf %lf",&D,&V)==2)
    {
        if(D==0 && V==0) break;
        D=D*D*D;
        V=(V*6)/PI;
        printf("%.3lf\n",pow( D-V , frac));
    }
    return 0;
}
