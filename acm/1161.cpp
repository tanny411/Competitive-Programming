#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define ll long long

#define fs first
#define sc second
//modified
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v(n),cnt(10003);
        vector<ll>r(10003);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            cnt[v[i]]++;
        }
        for(ll i=10000;i>0;i--)
        {
            ll ans=0,sum=cnt[i];
            for(ll j=i+i;j<=10000;j+=i)
            {
                ans-=r[j];
                sum+=cnt[j];
            }
            ans+=(sum*(sum-1)*(sum-2)*(sum-3))/24;
            r[i]=ans;
        }
        cout<<"Case "<<cas++<<": "<<r[1]<<"\n";
        //for(int i=0;i<=mx;i++) cout<<" "<<cnt[i]; cout<<endl;
    }
    return 0;
}

