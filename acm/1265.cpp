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
        int tg,d;
        cin>>tg>>d;
        cout<<"Case "<<test++<<": "<<fixed<<setprecision(10);
        if(tg&1) cout<<0.00<<endl;
        else cout<<1.0/(1.0*tg+1.0)<<endl;
    }
    return 0;
}

