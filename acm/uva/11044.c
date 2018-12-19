#include<stdio.h>
#include<math.h>
int main()
{
    double n,m;
    int test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%lf %lf",&n,&m);
        printf("%.0lf\n",ceil((n-2)/3)*ceil((m-2)/3));
    }
    return 0;
}
