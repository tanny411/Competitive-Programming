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

pii xy;

int egcd(int a,int b)
{
    if(b==0)
    {
       xy.first=1;
       xy.second=0;
       return a;
    }
    int g=egcd(b,a%b);
    int x=xy.first;
    int y=xy.second;
    xy.first=y;
    xy.second=x-(a/b)*y;
    return g;
}

int main()
{
    int a,b,flag;
    while(scanf("%d %d",&a,&b)==2)
    {
        flag=0;
        if(b>a)
        {
            int t=a;
            a=b;
            b=t;
            flag=1;
        }
        int g=egcd(a,b);
        if(flag)
        {
            int t=xy.first;
            xy.first=xy.second;
            xy.second=t;;
        }
        printf("%d %d %d\n",xy.first,xy.second,g);
    }
    return 0;
}
