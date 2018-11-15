WA
#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define LLU unsigned long long

#define fs first
#define sc second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int ara[m][n],in[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) cin>>ara[i][j],in[i][ara[i][j]-1]=j;
    }
    ll ans=0;
    int st[m];
    for(int i=0;i<n;)
    {
        int num=ara[0][i];
        for(int j=0;j<m;j++) st[j]=in[j][num]+1;
        ll hobe=1;
        while(1)
        {
            int j;
            for(j=0;j<m;j++)
            {
                if(st[j]>=n) break;
                if(j>0)
                {
                    if(ara[j][st[j]]!=ara[j-1][st[j-1]]) break;
                }
            }
            if(j<m) break;
            for(j=0;j<m;j++) st[j]++;
            hobe++;
        }
        ans+=hobe*(hobe+1)/2;
        i+=hobe;
    }
    cout<<ans<<endl;
    return 0;
}

