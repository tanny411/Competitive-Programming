#include<bits/stdc++.h>
#define pii pair<int,int>
#define ppp pair<pii,pii>
#define pppi pair<ppp,int>
#define fs first
#define sc second
using namespace std;
int flag[11][11][11][11];///flag (i,j)th knight at position (p,q);
int dist[11][11][11][11];
int sum[11][11];
int cnt[11][11];
int dx[]={1,1,2,2,-1,-1,-2,-2};
int dy[]={2,-2,1,-1,2,-2,1,-1};

int main()
{
    int t;
    cin>>t;
    for(int test=1;test<=t;test++)
    {
        memset(flag,0,sizeof flag);
        //memset(dist,0,sizeof dist);//lagbena
        memset(sum,0,sizeof sum);
        memset(cnt,0,sizeof cnt);
        int n,m;
        cin>>n>>m;
        queue<pppi>q;
        int knights=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char x;
                cin>>x;
                if(isdigit(x))
                {
                    //cout<<"PUT "<<x<<endl;
                    q.push({ {{i,j},{i,j}},x-'0'});
                    cnt[i][j]++;
                    flag[i][j][i][j]=1;
                    dist[i][j][i][j]=0;
                    knights++;
                }
            }
        }

//        for(int i=0;i<n;i++){
//            for(int j=0;j<m;j++){
//                cout<<" "<<cnt[i][j];
//            }
//            cout<<endl;
//        }

        while(!q.empty())
        {
            pii s=q.front().fs.fs;
            pii u=q.front().fs.sc;
            int num=q.front().sc;
            //cout<<"Aise "<<s.fs<<" "<<s.sc<<" "<<u.fs<<" "<<u.sc<<endl;
            q.pop();
            queue<pii>Qnow;
            Qnow.push(u);
            for(int k=0;k<num;k++){///at most k moves at a time;
                queue<pii>Qnext;
                while(!Qnow.empty()){
                    pii U=Qnow.front();
                    Qnow.pop();
                    for(int i=0;i<8;i++){
                        int x=U.fs+dx[i];
                        int y=U.sc+dy[i];
                        if(x>=0 && y>=0 && x<n && y<m && flag[s.fs][s.sc][x][y]==0){
                            dist[s.fs][s.sc][x][y]=dist[s.fs][s.sc][u.fs][u.sc]+1;
                            sum[x][y]+=dist[s.fs][s.sc][x][y];
                            flag[s.fs][s.sc][x][y]=1;
                            cnt[x][y]++;
                            Qnext.push({x,y});
                        }
                    }
                }
                Qnow=Qnext;
            }
            while(!Qnow.empty()) q.push({{s,Qnow.front()},num}),Qnow.pop();
        }
        int mn=1<<30;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(cnt[i][j]==knights) mn=min(mn,sum[i][j]);
            }
        }

//        for(int i=0;i<n;i++){
//            for(int j=0;j<m;j++){
//                cout<<" "<<cnt[i][j];
//            }
//            cout<<endl;
//        }

        if(mn==1<<30) mn=-1;
        cout<<"Case "<<test<<": "<<mn<<endl;
    }
    return 0;
}
