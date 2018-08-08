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
        int n,m;
        scanf("%d%d",&n,&m);
        vector<int>v(n);
        for(int i=0;i<n;i++) scanf("%d",&v[i]);
        char ch;
        int x,y;
        while(m--){
            scanf(" %c",&ch);
            if(ch!='R') scanf("%d",&x);
            if(ch=='P') scanf("%d",&y);
            if(ch=='S') for(int i=0;i<n;i++) v[i]+=x;
            else if(ch=='M') for(int i=0;i<n;i++) v[i]*=x;
            else if(ch=='D') for(int i=0;i<n;i++) v[i]/=x;
            else if(ch=='R') reverse(v.begin(),v.end());
            else swap(v[x],v[y]);
        }
        printf("Case %d:\n",test++);
        for(int i=0;i<n;i++){
            if(i) printf(" ");
            printf("%d",v[i]);
        }
        printf("\n");
    }
    return 0;
}
/**
1
10 5
7 8 -10 2 3 1212 1 2 3 9
R
D 3
M 2
P 0 9
P 9 1
Case 1:
4 6 0 0 808 2 0 -6 4 2
*/

