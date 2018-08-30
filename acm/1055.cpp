#include<bits/stdc++.h>
#define pii pair<int,int>
#define fs first
#define sc second
#define CIN ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

struct ppp{
public:
    pii a,b,c;
    ppp(){}
    ppp(pii x,pii y,pii z){
        a=x;
        b=y;
        c=z;
    }
};

int dist[9][9][9][9][9][9];
string gr[10];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int main()
{
    CIN
    int t;
    cin>>t;
    for(int test=1;test<=t;test++){
        memset(dist,0,sizeof dist);
        int n;
        cin>>n;
        pii a,b,c;
        for(int i=0;i<n;i++) cin>>gr[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char x=gr[i][j];
                if(x=='A') a={i,j};
                else if(x=='B') b={i,j};
                else if(x=='C') c={i,j};
                if(x=='A' || x=='B' || x=='C') x='.';
                gr[i][j]=x;
            }
        }

        dist[a.fs][a.sc][b.fs][b.sc][c.fs][c.sc]=1;
        int found=0;
        queue<ppp>q;
        q.push(ppp(a,b,c));
        while(!q.empty()){
            ppp u=q.front();
            q.pop();
            //cout<<"FROM "<<u.a.fs<<" "<<u.a.sc<<"   "<<u.b.fs<<" "<<u.b.sc<<"   "<<u.c.fs<<" "<<u.c.sc<<"  WENT TO: "<<endl;
            for(int i=0;i<4;i++){
                int x,y;
                ppp v=u;

                ///A
                x=u.a.fs+dx[i];
                y=u.a.sc+dy[i];
                if(x>=0 && y>=0 && x<n && y<n && gr[x][y]!='#') v.a=pii(x,y);

                ///B
                x=u.b.fs+dx[i];
                y=u.b.sc+dy[i];
                if(x>=0 && y>=0 && x<n && y<n && gr[x][y]!='#') v.b=pii(x,y);

                ///C
                x=u.c.fs+dx[i];
                y=u.c.sc+dy[i];
                if(x>=0 && y>=0 && x<n && y<n && gr[x][y]!='#') v.c=pii(x,y);
                ppp temp=v;
                if(v.a==v.b)
                {
                    v.a=u.a;
                    v.b=u.b;
                    if(v.b==v.c || v.a==v.c)
                        v.c=u.c;
                }
                if(v.a==v.c)
                {
                    v.a=u.a;
                    v.c=u.c;
                    if(v.b==v.c || v.b==v.a)
                        v.b=u.b;
                }
                if(v.b==v.c)
                {
                    v.b=u.b;
                    v.c=u.c;
                    if(v.b==v.a ||v.c==v.a)
                        v.a=u.a;
                }

                if(dist[v.a.fs][v.a.sc][v.b.fs][v.b.sc][v.c.fs][v.c.sc]==0){
                    //cout<<"      "<<v.a.fs<<" "<<v.a.sc<<"   "<<v.b.fs<<" "<<v.b.sc<<"   "<<v.c.fs<<" "<<v.c.sc<<endl;
                    dist[v.a.fs][v.a.sc][v.b.fs][v.b.sc][v.c.fs][v.c.sc]=dist[u.a.fs][u.a.sc][u.b.fs][u.b.sc][u.c.fs][u.c.sc]+1;
                    if(gr[v.a.fs][v.a.sc]=='X' && gr[v.b.fs][v.b.sc]=='X' && gr[v.c.fs][v.c.sc]=='X'){
                        found=dist[v.a.fs][v.a.sc][v.b.fs][v.b.sc][v.c.fs][v.c.sc];
                        //cout<<"      "<<temp.a.fs<<" "<<temp.a.sc<<"   "<<temp.b.fs<<" "<<temp.b.sc<<"   "<<temp.c.fs<<" "<<temp.c.sc<<endl;
                        //cout<<"      "<<v.a.fs<<" "<<v.a.sc<<"   "<<v.b.fs<<" "<<v.b.sc<<"   "<<v.c.fs<<" "<<v.c.sc<<endl;
                        //cout<<"      "<<u.a.fs<<" "<<u.a.sc<<"   "<<u.b.fs<<" "<<u.b.sc<<"   "<<u.c.fs<<" "<<u.c.sc<<endl;
                        break;
                    }
                    q.push(v);
                }

            }
            if(found>0) break;
        }
        if(found>0) cout<<"Case "<<test<<": "<<found-1<<endl;
        else cout<<"Case "<<test<<": trapped\n";
    }
    return 0;
}
/**
1
4
.B..
..A.
CX..
X.X.
ans : 2
*/
/**
1
6
A#BCXX
.#....
X.....
......
......
......

ans:trapped
*/
