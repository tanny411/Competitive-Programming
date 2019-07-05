#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    freopen("round1a.txt","r",stdin);
    freopen("round1a_o.txt","w",stdout);
    int cas=1,t;

    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int ara[n+2][n+2];
        int ara2[n+2][n+2];
        memset(ara,-1,sizeof ara);
        for (int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) ara2[i][j]=1<<23;
            // cout<<(ara[i][j]);
            // cout<<endl;
        }
        int a[m+2],b[m+2],c[m+2];
        for(int i=0;i<m;i++){
            int x,y,w;
            cin>>x>>y>>w;
            ara[x][y]=ara[y][x]=w;
            ara2[x][y]=ara2[y][x]=w;
            a[i]=x;b[i]=y;c[i]=w;
        }
        //floyd
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(ara2[i][j]>ara2[i][k]+ara2[k][j]){
                        ara2[i][j]=ara2[i][k]+ara2[k][j];
                    }
                }
            }
        }
        int oops=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(ara[i][j]!=-1){
                    if(ara[i][j]!=ara2[i][j]) {oops=1;break;}
                }
            }
            if(oops) break;
        }
        if(oops) cout<<"Case #"<<cas++<<": Impossible"<<endl;
        else{
            cout<<"Case #"<<cas++<<": "<<m<<endl;
            for(int i=0;i<m;i++){
                cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl; 
            }
        }
    }

    return 0;
}