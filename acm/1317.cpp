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
    while(t--){
        double n,m,k,p;
        cin>>n>>m>>k>>p;
        ///k*E(k=1round)=sum of (probability of throwing a ball * 1)
        ///as all p are same, and there are n people, E(x)=n*p
        cout<<"Case "<<test++<<": "<<fixed<<setprecision(10)<<n*k*p<<endl;
    }
    return 0;
}

