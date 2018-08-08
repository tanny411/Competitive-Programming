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

///

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,test=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=0;
        while(n--){
            int x;
            cin>>x;
            if(x>0) ans+=x;
        }
        cout<<"Case "<<test++<<": "<<ans<<endl;
    }
    return 0;
}

