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
    ll ara[20];
    ara[0]=ara[1]=1;
    for(ll i=2;i<20;i++){
        ara[i]=ara[i-1]*i;
    }
    int t,test=1;
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        vector<int>v;
        for(int i=19;i>=0 && n;i--){
            if(ara[i]<=n) v.pb(i),n-=ara[i];
        }
        if(n==0) {
            printf("Case %d: ",test++);
            for(int i=v.size()-1;i>=0;i--){
                printf("%d!",v[i]);
                if(i) printf("+");
            }
            printf("\n");
        }
        else printf("Case %d: impossible\n",test++);
    }
    return 0;
}
/**
It is possible to use a greedy approach: since fact(n) > fact(0)+fact(1)+...+fact(n-1) (this is true for each n > 2) you can iterate from the greatest factorial(20!) to the smallest one, if fact[i] is less than or equal to N you must take it, decrease N by fact[i] and proceed with the next factorial. At the end, if N is 0 you found the solution, otherwise it is impossible to obtain N adding factorials.
*/

