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
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        int hobe=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(i==0) continue;
            if(v[i]<v[i-1]) hobe++;
        }
        if(hobe==0 || (hobe==1 && v[0]>=v[n-1])) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

