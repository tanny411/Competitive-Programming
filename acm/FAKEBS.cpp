#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define llu unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        unordered_map<int,int>mp,pos;
        vector<int>v(n+1),st;
        for(int i=1;i<=n;i++) cin>>v[i];
        st=v;
        sort(st.begin()+1,st.end());
        for(int i=1;i<=n;i++)
        {
            mp[st[i]]=i;
            pos[v[i]]=i;
        }
        while(q--)
        {
            int x;
            cin>>x;
            int ps=pos[x];
            int lo=1,hi=n,mid,big=0,small=0,totsmall=mp[x]-1,totbig=n-mp[x];
            while(lo<=hi)
            {
                mid=(lo+hi)/2;
                if(mid==ps) break;
                else if(mid<ps)
                {
                    lo=mid+1;
                    if(v[mid]>x) big++;
                    else totsmall--;
                }
                else
                {
                    hi=mid-1;
                    if(v[mid]<x) small++;
                    else totbig--;
                }
            }
            if(small==big) cout<<small<<endl;
            else if(small>big)
            {
                if(small<=totbig) cout<<small<<endl;
                else cout<<-1<<endl;
            }
            else
            {
                if(big<=totsmall) cout<<big<<endl;
                else cout<<-1<<endl;
            }
        }
    }
    return 0;
}

