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
        double a,k,h;
        cin>>a>>k;
        h=a/2.0;

        vector<double>v(3);
        for(int i=0;i<3;i++) cin>>v[i],v[i]+=h+k;
        sort(v.begin(),v.end());

        cout<<fixed<<setprecision(5);

        double rt=v[0];
        double lft=max(v[1],v[2]);
        lft=lft-h-k-h-k;
        double ans;
        if(lft>rt) ans=0;
        else ans=min(a,rt-lft);
        cout<<ans*a<<endl;
    }
    return 0;
}

