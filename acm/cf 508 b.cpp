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
    LL n;
    cin>>n;
    if(n<=2) cout<<"No\n";
    else{
        cout<<"Yes\n";
        if(n&1) {
            cout<<1<<" "<<n<<endl;
            cout<<n-1;
            for(int i=1;i<n;i++) cout<<" "<<i;
        }
        else {
            cout<<2<<" "<<n<<" "<<n/2<<endl;
            cout<<n-2;
            for(int i=1;i<n;i++) if(i!=(n/2)) cout<<" "<<i;
        }
    }

    return 0;
}
