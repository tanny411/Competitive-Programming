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
        vector<ll>a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        int hobe=1;
        for(int i=0;i<n-2;i++)
        {
            if(b[i]<a[i]) {hobe=0; break;}
            if(b[i]>a[i]){
                ll x=b[i]-a[i];
                a[i]+=x;
                a[i+1]+=2ll*x;
                a[i+2]+=3ll*x;
            }
        }
        if(hobe && a[n-2]==b[n-2] && a[n-1]==b[n-1]) cout<<"TAK\n";
        else cout<<"NIE\n";
    }
    return 0;
}

