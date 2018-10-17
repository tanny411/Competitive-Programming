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
map<ll,bool>mp;
bool rec(ll p,ll n)
{
    if(mp.find(p)!=mp.end()) return mp[p];
    if(p>=n) return mp[p]=false;
    for(int i=2;i<=9;i++) if(!rec(1ll*p*i,n)) return mp[p]=true;
    return mp[p]=false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    ll n;
    while(cin>>n)
    {
        mp.clear();
        if(rec(1,n)) cout<<"Stan wins.\n";
        else cout<<"Ollie wins.\n";
    }
    return 0;
}

