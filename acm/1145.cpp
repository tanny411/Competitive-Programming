#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define mod 100000007

#define ll long long
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
        int n,k,s;
        cin>>n>>k>>s;
        ll ara[2][s+3];
        int in=1;

        ara[1][0]=ara[0][0]=0;
        for(int dice=1;dice<=n;dice++)
        {
            in=1-in;
            for(int i=1;i<=s;i++){
                ///notice: ara[in][i]=sum(ara[1-in][i-1] to ara[1-in][i-k-1])
                if(dice==1) {if(i<=k) ara[in][i]=1; else ara[in][i]=0;}
                else {
                    ara[in][i]=( (ara[in][i-1]+ara[1-in][i-1]-(i-k-1<0?0:ara[1-in][i-k-1]) )%mod + mod )%mod;
                }
            }
        }
        cout<<"Case "<<test++<<": "<<ara[in][s]<<endl;
    }
    return 0;
}
