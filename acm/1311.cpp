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

///ios_base::sync_with_stdio(false);

using namespace std;

int main()
{
    int t,test=1;
    cin>>t;
    while(t--){
        double v1,v2,v3,a1,a2;
        cin>>v1>>v2>>v3>>a1>>a2;
        double t1=v1/a1;
        double t2=v2/a2;
        cout<<"Case "<<test++<<": "<<fixed<<setprecision(10)<<(v1*t1-0.5*a1*t1*t1)+(v2*t2-0.5*a2*t2*t2)<<" "<<v3*(max(t1,t2))<<endl;
    }
    return 0;
}
