#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define LLU unsigned long long

#define fs first
#define sc second

using namespace std;
vector<ll>v(200010);
int n;
ll func(int m)
{
    ll sum=v[0];
    ll prev=v[0];
    ll temp=-1;
    //cout<<prev<<" ";
    for(int i=1;i<=m;i++)
    {
        if(v[i]<prev)
        {
            ll x=ceil(prev/(1.0*v[i]));
            prev=x*v[i];
            sum+=prev;
        }
        else sum+=v[i],prev=v[i];
        //cout<<prev<<" ";
    }
    //cout<<prev<<endl;
    if(m==n-1) return sum;

    sum-=prev;
    temp=v[m];
    v[m]=prev;

    prev=v[n-1];
    sum+=prev;
    //cout<<prev<<" ";
    for(int i=n-2;i>=m;i--)
    {
        if(v[i]<prev)
        {
            ll x=ceil(prev/(1.0*v[i]));
            prev=x*v[i];
            sum+=prev;
        }
        else sum+=v[i],prev=v[i];
        //cout<<prev<<" ";
    }
    //cout<<endl;
    v[m]=temp;
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=0;i<n;i++) cin>>v[i];
        int lo=0,hi=n-1;
        while(hi-lo>=3)
        {
            int step=(hi-lo)/3;
            int m1=lo+step;
            int m2=hi-step;
            ll x1=func(m1);
            ll x2=func(m2);
            if(x1>x2)lo=m1+1;
            else hi=m2;
        }
        ll ans=func(lo);
        ans=min(ans,func(lo+1));
        ans=min(ans,func(lo+2));
        cout<<ans<<endl;
    }
    return 0;
}

