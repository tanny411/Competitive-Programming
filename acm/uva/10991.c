#include<stdio.h>
#include<math.h>

double angle(double a1,double a2,double a3)
{
    return acos((a1*a1 + a2*a2 - a3*a3)/( 2*a1*a2 ));
}
int main()
{
    int t,i;
    double r[3],ulala;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<3;i++)
        {
            scanf("%lf",&r[i]);
        }
        ulala=(sqrt((r[0]+r[1]+r[2])*r[2]*r[0]*r[1])) -
        ((( angle(r[0]+r[1],r[0]+r[2],r[1]+r[2]) )*r[0]*r[0]/2)+((angle(r[2]+r[0],r[1]+r[2],r[0]+r[1]) )*r[2]*r[2]/2)+(( angle(r[0]+r[1],r[1]+r[2],r[0]+r[2]) )*r[1]*r[1]/2));
        printf("%lf \n",ulala);
    }
    return 0;
}
