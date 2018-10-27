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
bool cmp(pii a,pii b){
    return a.sc<b.sc;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pii>v;
        vector< pair<int,pii> >p;
        for(int i=0;i<n;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            v.pb(pii(a,a));
            v.pb(pii(b,c));
            p.pb({a,{b,c}});
        }
        sort(v.begin(),v.end(),cmp);
        int x=v[0].sc;
        vector<int>mp(1000003),ase(1000003);
        mp[x]=1;
        int cnt=1;
        for(int i=0;i<v.size();i++)
        {
            if(x<v[i].fs) x=v[i].sc,mp[x]++,cnt++;
        }
        for(int i=1;i<1000003;i++)
        {
            mp[i]+=mp[i-1];
        }
        for(int i=0;i<n;i++)
        {
            int a=p[i].fs;
            int b=p[i].sc.fs;
            int c=p[i].sc.sc;
            if(a>=b && a<=c && mp[c]-mp[b-1]==1 && ase[a]==0) ase[a]++,cnt++;
        }
        cout<<"Case #"<<test++<<": "<<cnt<<endl;
    }
    return 0;
}

