#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define LL long long
#define LLU unsigned long long

#define fs first
#define sc second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    int n,r;
    cin>>n>>r;
    int ara[n+2];
    memset(ara,0,sizeof ara);
    for(int i=0;i<r;i++)
    {
        int x;
        cin>>x;
        ara[x]=1;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(!ara[i]) cout<<i<<" ",cnt++;
    }
    if(cnt==0) cout<<"*";
    return 0;
}
