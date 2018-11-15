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
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    int n;
    cin>>n;
    vector<int>v(n),a(n);
    for(int i=0;i<n;i++) cin>>v[i], a[i]=v[i]-(i>0?v[i-1]:0);
    //for(int i=0;i<n;i++) cout<<" "<<a[i];
    vector<int>ans;
    for(int i=1;i<=n;i++)
    {
        int j;
        for(j=0;j<n;j++)
        {
            if(a[j%i]!=a[j]) break;
        }
        if(j==n) ans.pb(i);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}

