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

///

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.rbegin(),v.rend());
    int i=0,j=n-1;
    ll ans=0;
    while(i+m<j-m)
    {
        ans+=v[i]-v[j];
        i+=m;
        j-=m;
    }
    ans+=v[i]-v[j];
    cout<<ans*2<<endl;
    return 0;
}

