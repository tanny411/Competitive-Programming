#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define mod 1000000007

#define ll long long
#define LLU unsigned long long

#define fs first
#define sc second

using namespace std;
int flag[305];
vector<int>prime;
void sieve(int n)
{
    prime.pb(2);
    for(int i=3;i<n;i++){
        if(!flag[i]){
            prime.pb(i);
            for(int j=i*i;j<n;j+=(i+i)) flag[j]=1;
        }
    }
}
ll bg(ll base, ll power)
{
    if(power==0) return 1ll;
    ll x=bg(base,power/2);
    x=(x*x)%mod;
    if(power&1) x=(x*base)%mod;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    sieve(300);
    int row=prime.size();
    //cout<<"prime size "<<prime.size()<<endl;
    int mat[row+3][1005];
    int t,test=1;
    cin>>t;
    while(t--)
    {
        memset(mat,0,sizeof mat);
        int col;
        cin>>col;
        for(int i=0;i<col;i++)
        {
            ll x;
            cin>>x;
            for(int j=0;j<row && x>1;j++)
            {
                while(x%prime[j]==0){
                    x/=prime[j];
                    mat[j][i]^=1;
                }
            }
        }
        int zero=0;
        for(int c=0,r=0;c<col && r<row;c++)
        {
            if(!mat[r][c]){
                for(int i=r+1;i<row;i++){
                    if(mat[i][c]) {swap(mat[i],mat[r]);break;}
                }
            }
            if(!mat[r][c]){ zero++; continue; }
            for(int i=0;i<row;i++){
                if(i==r) continue;
                if(mat[i][c]) {
                    for(int j=c;j<col;j++){///cuz ager gula already 0
                        mat[i][j]^=mat[r][j];
                    }
                }
            }
            r++;
        }
        ll ans=(bg(2,zero)-1+mod)%mod;
        cout<<"Case "<<test++<<": "<<ans<<endl;
    }
    return 0;
}
