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

ll dp[22][5];
ll ara[22][5],n;

ll rec(int pos,int color)
{
    if(pos==n) return 0;
    if(dp[pos][color]!=-1) return dp[pos][color];
    ll ret=1<<30;
    for(int i=0;i<3;i++)
    {
        if(i!=color) ret=min(ret,rec(pos+1,i));
    }
    return dp[pos][color]=ret+ara[pos][color];
}

int main()
{
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>ara[i][j];
            }
        }
        printf("Case %d: ",cas++);
        ll a=rec(0,0);
        ll b=rec(0,1);
        ll c=rec(0,2);
        cout<<min(a,min(b,c))<<endl;
    }
    return 0;
}
