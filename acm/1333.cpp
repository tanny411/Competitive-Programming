#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define mod 1000000000

#define ll long long
#define LLU unsigned long long

#define fs first
#define sc second

using namespace std;
map<int,vector<int> >mp;
ll bg(ll base, ll power, ll m)
{
    if(power==0) return 1ll;
    if(power==1) return base%m;
    ll x=bg(base, power/2, m);
    x=(x*x)%m;
    if(power&1) x=(x*base)%m;
    return x;
}
bool ase(int x,int y)
{
    for(int i=0;i<mp[x].size();i++) if(mp[x][i]==y) return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        mp.clear();
        int n,m,k,b;
        cin>>n>>m>>k>>b;
        for(int i=0;i<b;i++)
        {
            int x,y;
            cin>>x>>y;
            mp[x].pb(y);
        }
        ll type1=0;
        ll type2=0;
        int ase=1;
        set<int>s;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            int row=it->fs;
            if(row==1) type1+=m-mp[row].size(),ase=0;
            else{
                int bothx=0;
                for(int i=0;i<mp[row].size();i++)
                {
                    if(s.count(mp[row][i])>0) bothx++;
                }
                type2+=m-mp[row].size()-(s.size()-bothx);
                type1+=s.size()-bothx;
            }
            s.clear();
            int flag=0;
            if(mp.find(row+1)==mp.end()) flag=1;
            if(row==n) continue;
            for(int i=0;i<mp[row].size();i++)
            {
                if(!flag) s.insert(mp[row][i]);
                else type1++,type2--;
            }
            //cout<<"areh "<<type1<<" "<<type2<<endl;
        }
        //cout<<type1<<" "<<type2<<endl;
        type1+=ase*m;
        type2+=1ll*m*(n-mp.size())-ase*m;
        ll ans=bg(k,type1,mod);
        ans=(ans*bg(k-1,type2,mod))%mod;
        cout<<"Case "<<test++<<": "<<ans<<endl;
    }
    return 0;
}
/*
100
3 4 2 4
2 1 2 2 2 3 2 4
*/
