#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define llu unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    int t,test=1;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        if(__builtin_popcount(x)&1) cout<<"Case "<<test++<<": odd\n";
        else cout<<"Case "<<test++<<": even\n";
    }
    return 0;
}

