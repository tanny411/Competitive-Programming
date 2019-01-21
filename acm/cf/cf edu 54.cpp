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
///c
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        double d;
        cin>>d;
        double dd=d*d-4*d;
        if(dd<0) cout<<"N\n";
        else{
            dd=sqrt(dd);
            cout<<"Y "<<fixed<<setprecision(10)<<(d+dd)/2.0<<" "<<(d-dd)/2.0<<endl;
        }
    }
    return 0;
}

