#include<stdio.h>
///#include<math.h>
int main()
{
    int r,n;
    while(scanf("%d %d",&r,&n)==2)
    {
        printf("%.3lf\n",n*(.5*r*r*sin(4*acos(0)/n)));
    }
    return 0;
}
