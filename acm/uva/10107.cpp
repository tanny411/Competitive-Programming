#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
    int odd=1,no=1,ara[10002],x;
    while(scanf("%d",&ara[no])==1)
    {
        sort(ara,ara+no+1);
        if(odd) printf("%d\n",ara[(no+1)/2]);
        else {x=no/2; printf("%d\n",(ara[x]+ara[x+1])/2);}
        no++;
        odd=1-odd;
    }
    return 0;
}
