#include<stdio.h>

int main()
{
    int test=1;
    double n,A;
    while(scanf("%lf",&n)==1 && n!=0)
    {
        A=(3+sqrt(9+8*n))/2;
        printf("Case %d: %.0lf\n",test++,ceil(A));
    }
    return 0;
}
