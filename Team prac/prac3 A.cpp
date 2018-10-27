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
int root[200];
int Find(int x)
{
    if(root[x]==x) return x;
    else return root[x]=Find(root[x]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        ll n,d;
        cin>>n>>d;
        vector<ll>v(n);
        for(int i=0;i<n;i++) root[i]=i;
        for(int i=0;i<n;i++) cin>>v[i];
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(abs(v[i]-v[j])<=d){
                    int a=Find(i);
                    int b=Find(j);
                    if(a!=j) root[a]=b;
                }
            }
        }
        set<int>s;
        for(int i=0;i<n;i++)
        {
            s.insert(Find(i));
        }
        cout<<"Case #"<<test++<<": "<<s.size()<<endl;
    }
    return 0;
}

