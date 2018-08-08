#include<iostream>
#include<vector>
#include<cstring>

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
int ara[50][50];
vector<int>gr[1050];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int match[1050],seen[1050];

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
        int j;
        if(i&1) j=1;
        else j=0;
        for(;j<m;j+=2)
        {
            if(ara[i][j]==-1) continue;
            memset(seen,0,sizeof seen);
            if(bpm(ara[i][j])) res++;
        }
    }
    return res;
}
void check()
{
    for(int i=1;i<=14;i++)
    {
        cout<<i<<": ";
        for(int j=0;j<gr[i].size();j++)
        {
            cout<<" "<<gr[i][j];
        }
        cout<<endl;
    }
    cout<<"BPM "<<Maxbpm()<<endl;

    for(int i=0;i<n;i++)
    {
        int j;
        if(i&1) j=0;
        else j=1;
        for(;j<m;j+=2)
        {
            if(ara[i][j]==-1) continue;
            cout<<ara[i][j]<<" "<<match[ ara[i][j] ]<<endl;
        }
    }
}
int main()
{
    int holes;
    cin>>n>>m>>holes;

    memset(ara,0,sizeof ara);
    for(int i=0;i<n*m+3;i++) gr[i].clear();

    for(int i=0;i<holes;i++)
    {
        int x,y;
        cin>>x>>y;
        ara[y-1][x-1]=-1;
    }

    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(ara[i][j]==0) ara[i][j]=++cnt;
        }
    }
    //for(int i=0;i<n;i++) {for(int j=0;j<m;j++) printf("  %#3d",ara[i][j]); cout<<endl;}
    if(cnt&1) {cout<<"NO\n";return 0;}

    for(int i=0;i<n;i++)
    {
        int j;
        if(i&1) j=1;
        else j=0;
        for(;j<m;j+=2)
        {
            if(ara[i][j]==-1) continue;
            for(int k=0;k<4;k++)
            {
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0 && y>=0 && x<n && y<m && ara[x][y]!=-1)
                gr[ ara[i][j] ].pb(ara[x][y]);
            }
        }
    }

    //check();

    if(Maxbpm()==cnt/2) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}

