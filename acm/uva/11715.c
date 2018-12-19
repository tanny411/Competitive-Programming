#include<stdio.h>
#include<math.h>

int main()
{
    int i,test=1;
    double u,v,a,t,s;
    while(scanf("%d",&i)==1)
    {
        printf("Case %d: ",test++);
        if(i==1)
        {
            scanf("%lf %lf %lf",&u,&v,&t);
            printf("%.3lf %.3lf\n",(u+v)*t/2,(v-u)/t);
        }
        else if(i==2)
        {
            scanf("%lf %lf %lf",&u,&v,&a);
            t=(v-u)/a;
            printf("%.3lf %.3lf\n",(u+v)*t/2,t);
        }
        else if(i==3)
        {
            scanf("%lf %lf %lf",&u,&a,&s);
            v=sqrt(u*u + 2*a*s);
            printf("%.3lf %.3lf\n",v,(v-u)/a);
        }
        else if(i==4)
        {
            scanf("%lf %lf %lf",&v,&a,&s);
            u=sqrt(v*v - 2*a*s);
            printf("%.3lf %.3lf\n",u,(v-u)/a);
        }
        else break;
    }
    return 0;
}
