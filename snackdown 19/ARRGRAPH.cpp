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

int p[55];

int Find(int x){
    if(p[x]==x) return x;
    else return p[x]=Find(p[x]);
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
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) p[i]=i;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
            {
                if(__gcd(a[i],a[j])==1) {
                    int pi=Find(i);
                    int pj=Find(j);
                    p[pi]=pj;
                }
            }
        }
        set<int>s;
        for(int i=0;i<n;i++) s.insert(Find(i));
        if(s.size()==1) cout<<0<<endl;
        else {
            cout<<1<<endl;
            if(a[0]!=47) a[0]=47;
            else a[0]=43;
        }
        for(int i=0;i<n;i++)
        {
            if(i) cout<<" ";
            cout<<a[i];
        }
        cout<<endl;
    }
    return 0;
}

