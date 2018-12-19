#include<bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
using namespace std;


#define pMax 5000001
unsigned long long phi[pMax];
bool prime[pMax];

void sievephi()
{
    int i,j;

    //for(i=1;i<pMax;i++) phi[i]=i;

    prime[1]=1;
    for(i=0;i<pMax;i+=2)
    {
        prime[i]=1;
        phi[i]=i/2;
    }
    prime[2]=0;
    for(i=1;i<pMax;i+=2) phi[i]=i;
    for(i=3;i<pMax;i+=2)
    {
        if(!prime[i])
        {
            for(j=i;j<pMax;j+=i)
            {
                prime[j]=1;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}

void square()
{
    ///using prime array for storing squares
    for(int i=2;i<pMax;i++)
    {
        phi[i] = phi[i]*phi[i] + phi[i-1];
    }
}

int main()
{
    sievephi();
    square();
    int T,t;
    long long a,b;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%lld %lld",&a,&b);
        printf("Case %d: %llu\n",t,phi[b]-phi[a-1]);
    }
    return 0;
}
