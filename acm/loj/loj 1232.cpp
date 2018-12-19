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
#define INTMAX 1<<30
#define MOD 100000007
#define ll long long
#define llu unsigned long long
#define eps .0000001
#define zero 0.0000000000000001
#define floatless(a,b) ( (a-b)<=eps )
#define floatequal(a,b) ( floatless(a,b) && floatless(b,a) )
#define incircle_r(a,b,c) 2*area(triangle)/perimeter(triangle)
#define circumcircle_R(a,b,c) a*b*c/sqrt( (a+b+c)*(a+b-c)*(b+c-a)*(c+a-b) )
#define circumcircle_2R_sinelaw a/sinA
#define triarea(a,b,c) sqrt( (a+b+c)*(b+c-a)*(a-b+c)*(a+b-c) )/9
#define mediantoarea(a,b,c) (4/3)*triarea(a,b,c)
using namespace std;

int n,coin[101],k;
ll amt[10010];

/*
ll dp[101][10001];
void reset()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            dp[i][j]=-1;
        }
    }
}

ll rec(int pos,int amnt)
{
    if(amnt==0) return 1;
    if(pos==n) return 0;
    if(amnt<0) return 0;
    if(dp[pos][amnt]!=-1) return dp[pos][amnt];
    ll ret=0;
    for(int i=0;i<=k;i++)
    {
        if(amnt-coin[pos]*i<0) break;
        ret+=rec(pos+1,amnt-coin[pos]*i)%MOD;
    }
    dp[pos][amnt]=ret;
    return ret;
}
*/
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        //reset();
        for(int i=0;i<n;i++) scanf("%d",&coin[i]);
        memset(amt,0,sizeof(amt));
        amt[0]=1;///only one way to make 0(not taking any coin at all)
        for(int i=0;i<n;i++)///coin
        {
            for(int j=coin[i];j<=k;j++)///amount
            {
                amt[j]=(amt[j]+amt[j-coin[i]])%MOD;
            }
        }
        printf("Case %d: %lld\n",cas++,amt[k]);
    }
    return 0;
}
