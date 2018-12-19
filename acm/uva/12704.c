
#include<stdio.h>
#include<math.h>

int main()
{

    double len,t,x,y,r;;
    scanf("%lf",&t);
    while(t--)
    {
        scanf("%lf %lf %lf",&x,&y,&r);
        len=sqrt(x*x+y*y);
        printf("%.2lf %.2lf\n",r-len,r+len);
    }
    return 0;
}
