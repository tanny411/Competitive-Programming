///ROOKS
#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

ll N,R;
ll ncr[35][35];

ll com(ll n,ll r)
{
    if(n==r) return 1;
    if(r==1) return n;
    if(ncr[n][r]!=-1) return ncr[n][r];
    ncr[n][r]=com(n-1,r)+com(n-1,r-1);
    return ncr[n][r];
}

void reset()
{
    for(int i=0;i<31;i++)
    {
        for(int j=0;j<31;j++)
        {
            ncr[i][j]=-1;
        }
    }
}

int main()
{
    reset();
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu %llu",&N,&R);
        printf("Case %d: ",cas++);
        if(R>N) { printf("0\n"); continue; }
        if(R==0) { printf("1\n"); continue; }
        ll p=1;
        ll i,j=N;
        for(i=0,j=N;i<R;i++,j--)
        {
            p*=j;
        }
        printf("%llu\n",com(N,R)*p);
    }
    return 0;
}
