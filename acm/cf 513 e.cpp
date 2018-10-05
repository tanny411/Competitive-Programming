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
int root[200002];
int S[200002];

int Find(int x){
    if(x==root[x]) return x;
    else return root[x]=Find(root[x]);
}

int main()
{
    ///nope --> concept bhul
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) root[i]=i;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        x=Find(x);
        y=Find(y);
        if(x!=y) root[x]=y;
    }
    for(int i=1;i<=n;i++) S[ Find(i) ]++;
    ll sum=0;
    for(int i=1;i<=n;i++) if(S[i]) sum+=(1ll*S[i]*(S[i]-1))/2;
    //for(int i=1;i<=n;i++) cout<<"  "<<S[i]<<endl;
    cout<<sum<<endl;
    return 0;
}

