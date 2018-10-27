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

#define euler 0.5772156649015328606065120900824024310421
using namespace std;
double ara[1000004];
int main()
{
    ios_base::sync_with_stdio(false);
    ara[1]=1;
    for(int i=2;i<1000001;i++)
    {
        ara[i]=1/(1.0*i) + ara[i-1];
    }
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n<=1000000) cout<<"Case "<<test++<<": "<<fixed<<setprecision(10)<<ara[n]<<endl;
        else cout<<"Case "<<test++<<": "<<fixed<<setprecision(10)<<log(n+0.5)+euler<<endl;
    }
    return 0;
}

