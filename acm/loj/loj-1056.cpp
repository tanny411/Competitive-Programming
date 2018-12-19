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
using namespace std;
int main()
{
    int t,cas=1;
    double m,n,s,rat,r;
    cin>>t;
    while(t--)
    {
        scanf("%lf : %lf",&m,&n);

        r=(m*m+n*n)/4;
        r=sqrt(r);
        s=r*2*atan(n/m);
        rat=200/(m+s);
        //cout<<rat<<endl;

        printf("Case %d: %.10lf %.10lf\n",cas++,m*rat,n*rat);
    }
    return 0;
}
