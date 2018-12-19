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
using namespace std;

int n,r,p,q;

int ftz(int x,int b)///factorial trailing zero
{
    int c=0;
    for(int i=b;i<=x;i*=b)
    {
        c+=(x/i);
    }
    return c;
}

int num(int b)
{
    int c=0;
    while(p%b==0)
    {
        c++;
        p/=b;
    }
    c*=q;
    c+=ftz(n,b)-ftz(r,b)-ftz(n-r,b);
    return c;
}

int main()
{
    //freopen("out.txt","w",stdout);
    int t,T;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d %d %d",&n,&r,&p,&q);
        printf("Case %d: %d\n",t,min(num(2),num(5)));
    }

    return 0;
}
