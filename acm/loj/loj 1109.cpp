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
#define MOD 1000000007
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
#define mx 1000

pii ara[1002];

bool comp(pii a,pii b)
{
    if(a.second==b.second) return a.first>b.first;
    else return a.second<b.second;
}

void divs()
{
    for(int i=1;i<=1000;i++)
    {
        ara[i].first=i;
        for(int j=i;j<=1000;j+=i)
        {
            ara[j].second++;
        }
    }
}

int main()
{
    divs();
    sort(ara,ara+1001,comp);
    //for(int i=1;i<=10;i++) cout<<ara[i].first<<" "<<ara[i].second<<endl;
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n;
        scanf("%d",&n);
        printf("Case %d: %d\n",i,ara[n].first);
    }
    return 0;
}
