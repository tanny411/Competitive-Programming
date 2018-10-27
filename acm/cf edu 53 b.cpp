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
    vector<int>a(n+4),b(n+4);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[x]=i+1;
    }
    int taken=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(i) cout<<" ";
        cout<<max(0,a[x]-taken);
        if(a[x]-taken>0) taken=a[x];
    }
    return 0;
}

