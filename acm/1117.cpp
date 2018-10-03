#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long

#define fs first
#define sc second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<int>p(m);
        for(int i=0;i<m;i++)
        {
            cin>>p[i];
        }
        ll lim=(1<<m);
        //cout<<"lim = "<<lim<<endl;
        ll ans=0;
        for(int i=1;i<lim;i++)
        {
            ll lcm=0;
            int cnt=0,bit=0;
            int temp=i;
            while(temp)
            {
                if(temp&1){
                    cnt++;
                    if(lcm==0) lcm=p[bit];
                    else lcm=(lcm*p[bit]/(__gcd(lcm,1ll*p[bit])));
                }
                bit++;
                temp/=2;
            }
            if(cnt&1) ans+=n/lcm;
            else ans-=n/lcm;
            //cout<<"sum = "<<n/lcm<<endl;
        }
        cout<<"Case "<<test++<<": "<<n-ans<<endl;
    }
    return 0;
}

