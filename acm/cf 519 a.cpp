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
    vector<int>v(n);
    int s=0,mx=-1;
    for(int i=0;i<n;i++) cin>>v[i],s+=v[i],mx=max(mx,v[i]);
    for(int k=mx;;k++)
    {
        if(n*k-s>s) {
            cout<<k<<endl;
            return 0;
        }
    }
    return 0;
}

