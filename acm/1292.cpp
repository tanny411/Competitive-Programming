#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>

#define fs first
#define sc second

using namespace std;
///n^2*logn
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pii>v(n);
        for(int i=0;i<n;i++) cin>>v[i].fs>>v[i].sc;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            map<double,int>mp;
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                double val;
                if(v[i].fs==v[j].fs) val=1e9;
                else val=(1.0*v[i].sc-v[j].sc)/(1.0*v[i].fs-v[j].fs);
                mp[val]++;
                ans=max(ans,mp[val]);
            }
        }
        cout<<"Case "<<test++<<": "<<ans+1<<endl;
    }
    return 0;
}

