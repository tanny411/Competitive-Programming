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

int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int p,l;
        cin>>p>>l;
        p-=l;
        vector<int>v;
        ll i;
        for(i=1; i*i<p; i++)
        {
            if(p%i==0)
            {
                if(i>l)v.pb(i);
                if(p/i > l)v.pb(p/i);
            }
        }
        if(i*i==p && i>l) v.pb(i);
        sort(v.begin(),v.end());
        cout<<"Case "<<test++<<":";
        for(int i=0; i<v.size(); i++)
        {
            cout<<" "<<v[i];
        }
        if(v.empty())
            cout<<" impossible";
        cout<<endl;
    }
    return 0;
}

