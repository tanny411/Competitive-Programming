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
/**
1. find one route, that has the maximum probability to send the message successfully
by dijkstra or floydwarshall
2.The probability of success is p, if successful, the expected time is p*2k,
if unsuccessful, the expected value is (1-p)*(E +2k) //wasted 2k time, then have to resend
Therefore E=p*2k+(1-p)*(E+2k)
simplification is E=2k/p
3.then multiply s
4. ans=2*k*s/p
*/
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n,m;
        double s,K;
        cin>>n>>m>>s>>K;
        double dis[n+1][n+1];
        memset(dis,0,sizeof dis);
        while(m--)
        {
            int x,y;
            double w;
            cin>>x>>y>>w;
            dis[x][y]=dis[y][x]=w/100.0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dis[i][j]=max(dis[i][j],dis[i][k]*dis[k][j]);
                }
            }
        }
        cout<<"Case "<<test++<<": "<<fixed<<setprecision(10)<<(2.0*s*K)/dis[0][n-1]<<endl;
    }
    return 0;
}

