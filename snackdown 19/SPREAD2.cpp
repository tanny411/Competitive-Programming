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
        int n;
        cin>>n;
        vector<ll>v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        for(int i=1;i<n;i++) v[i]+=v[i-1];
        ll cnt=0;
        for(int i=0;i<n;)
        {
            ll num=i+v[i];
            cnt++;
            if(num>=n-1) break;
            i=num;
        }
        cout<<cnt<<endl;
    }
    return 0;
}

