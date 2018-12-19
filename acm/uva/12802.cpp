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
#define pMax 1000002

int prime[pMax];

void sieve()
{
    int i,j,root=1001;
    prime[1]=1;
    for(i=0;i<pMax;i+=2) prime[i]=1;
    prime[2]=0;
    for(i=3;i<root;i++)
    {
        if(!prime[i])
        {
            for(j=i*i;j<pMax;j+=(i+i)) prime[j]=1;
        }
    }
}

int ispalindrome(int a)
{
    int x=a;
    int m=0;
    while(a)
    {
        m=m*10+(a%10);
        a/=10;
    }
    if(x==m) return 1;
    return 0;
}


int main()
{
    sieve();
    int a,flag=0;
    while(scanf("%d",&a)==1)
    {
        if(flag) continue;
        printf("%d\n",2*a);
        if(ispalindrome(a) && !prime[a]) flag=1;
    }
    return 0;
}
