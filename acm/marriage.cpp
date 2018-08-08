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

///ios_base::sync_with_stdio(false);

using namespace std;
int n,m;
vector<int>gr[150];
int match[150],seen[150];
bool bpm(int u)
{
    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i];
        if(!seen[v])
        {
            seen[v]=1;
            if(match[v]==-1 || bpm(match[v]))
            {
                match[v]=u;
                return true;
            }
        }
    }
    return false;
}
int Maxbpm()
{
    int res=0;
    memset(match,-1,sizeof match);
    for(int i=0;i<n;i++)
    {
        memset(seen,0,sizeof seen);
        if(bpm(i)) res++;
    }
    return res;
}
int main()
{
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<m+n+2;i++) gr[i].clear();
        int ht[n],age[n],div[n];
        for(int i=0;i<n;i++)
        {
            cin>>ht[i]>>age[i]>>div[i];
        }
        for(int i=0;i<m;i++)
        {
            int h,a,d;
            cin>>h>>a>>d;
            for(int j=0;j<n;j++)
            {
                if(abs(h-ht[j])<=12 && abs(a-age[j])<=5 && div[j]==d)
                {
                    gr[j].pb(i+n);
                }
            }
        }
        cout<<"Case "<<cas++<<": "<<Maxbpm()<<endl;
    }
    return 0;
}

