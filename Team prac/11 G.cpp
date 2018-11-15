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
string s[102];
int n,m;
int dis[10][102][102],vis[102][102],dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int cnt;
void dijkstra(int in,int i, int j)
{
    cnt++;
    dis[in][i][j]=0;
    priority_queue<pair<int,pii>,vector<pair<int,pii> >,greater< pair<int,pii> > >pq;
    pq.push({0,{i,j}});
    while(!pq.empty())
    {
        pii u=pq.top().sc;
        pq.pop();
        if(vis[u.fs][u.sc]==cnt) continue;
        vis[u.fs][u.sc]=cnt;
        for(int k=0;k<4;k++)
        {
            int x=dx[k]+u.fs;
            int y=dy[k]+u.sc;
            if(x>=0 && y>=0 && x<n && y<m && vis[x][y]!=cnt && s[x][y]!='0')
            {
                int sd=s[x][y]-'0';
                if(s[x][y]=='A' || s[x][y]=='B') sd=0;
                int dd=dis[in][u.fs][u.sc]+sd;
                if(dis[in][x][y]>dd)
                {
                    dis[in][x][y]=dd;
                    if(s[x][y]=='A' || s[x][y]=='B') ;
                    else pq.push({dd,{x,y}});
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        pii A,B;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='A') A.fs=i,A.sc=j;
                else if(s[i][j]=='B') B.fs=i,B.sc=j;
                else sum+=s[i][j]-'0';
            }
        }
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        {
            for(int k=0;k<2;k++) dis[k][i][j]=1<<30;
        }
        dijkstra(0,A.fs,A.sc);
        dijkstra(1,B.fs,B.sc);
        int ans=-1<<30;
        //cout<<"sum "<<sum<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dis[0][i][j]< 1<<30 && dis[1][i][j]< 1<<30)
                {
                    //cout<<"Aise "<<i<<" "<<j<<"\n";
                    int sd=(s[i][j]-'0');
                    if(s[i][j]=='A' || s[i][j]=='B') sd=0;
                    if(s[i][j]=='0') continue;
                    int x=sum-dis[0][i][j]-dis[1][i][j]+2*sd;
                    ans=max(ans,x);
                }
            }
        }
        //cout<<"polo "<<ans<<endl;
        if(ans==-1<<30) ans=0;
        cout<<"Case #"<<test++<<": "<<ans<<endl;
    }
    return 0;
}

