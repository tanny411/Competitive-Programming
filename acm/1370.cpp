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

#define MX 1000000+10
int phi[MX+2];
int dp[MX+2];
vector<pii>v;
void sievephi()
{
    for(int i=2;i<=MX;i++)
    {
        phi[i]=i;
    }
    for(int i=2;i<=MX;i++)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<=MX;j+=i)
            {
                phi[j]-=phi[j]/i;
            }
        }
    }
    phi[1]=0;
    ///started the loop from 0 and got WA, cuz phi[0]=0 wrongly saved
    for(int i=1;i<=MX;i++) if(!dp[phi[i]]) dp[phi[i]]=1,v.pb(pii(phi[i],i));
    sort(v.begin(),v.end());
    for(int i=v.size()-2;i>=0;i--)
    {
        v[i].sc=min(v[i].sc,v[i+1].sc);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    sievephi();///375000 first index with phi==1000000
    //cout<<v.size()<<endl;
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll ans=0;
        while(n--)
        {
            int x;
            cin>>x;
            ans+=(ll)v[ lower_bound(v.begin(),v.end(),pii(x,0))-v.begin() ].sc;
        }
        cout<<"Case "<<test++<<": "<<ans<<" Xukha"<<endl;
    }
    return 0;
}
/**
4
1
20
1
24
1
1104
26
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26

Case 1: 23 Xukha
Case 2: 29 Xukha
Case 3: 1109 Xukha
Case 4: 413 Xukha
*/
