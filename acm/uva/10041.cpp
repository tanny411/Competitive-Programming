#include <bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
using namespace std;

int main() {

    int mn,n,i,j;
    int t,ara[600],sum;
    scanf("%d",&t);
    while(t--)
    {
        mn=1<<30;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&ara[i]);
        }
        for(i=0;i<n;i++)
        {
            sum=0;
            for(j=0;j<n;j++)
            {
                sum+=ara[i]>ara[j]?ara[i]-ara[j]:ara[j]-ara[i];
            }
            if(mn>sum)
            {
                mn=sum;
            }
        }
        printf("%d\n",mn);
    }
    return 0;
}
