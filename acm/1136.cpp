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
    scanf("%d",&t);
    while(t--){
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        int ans=(y/3)*2 + (y%3==2?1:0) - ( (x/3)*2 + (x%3==2?1:0) );
        printf("Case %d: %d\n",test++,ans);
    }
    return 0;
}

