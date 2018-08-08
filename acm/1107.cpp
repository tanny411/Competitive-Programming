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
        int lx,ly,hx,hy;///lower and higher (x,y)
        scanf("%d%d%d%d",&lx,&ly,&hx,&hy);
        printf("Case %d:\n",test++);
        int m;
        scanf("%d",&m);
        while(m--){
            int x,y;
            scanf("%d%d",&x,&y);
            if(x>lx && x<hx && y>ly && y<hy) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}

