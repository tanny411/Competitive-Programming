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
    int t,n,m,test=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int ans=(int)ceil((n*m)/2.0);
        if(n==1 || m==1) ans=m*n;
        if(n==2 || m==2){
            if(n==2) n=m;
            if(n==2) ans=4;
            else if(n%2==1){

            }
        }
        printf("Case %d: %d\n",test++,ans);
    }
    return 0;
}
