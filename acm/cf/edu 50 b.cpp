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
    int q;
    cin>>q;
    while(q--){
        LL x,y,moves;
        cin>>x>>y>>moves;
        LL ans1=x+abs(x-y);
        LL ans2=y+abs(x-y);
        if(ans1>moves && ans2>moves){
            cout<<-1<<endl;
            continue;
        }
        LL extra1=moves-ans1;
        LL extra2=moves-ans2;
        int f1=extra1>=0;
        int f2=extra2>=0;
        if(abs(x-y)%2==1) ans1--,ans2--;
        if(extra1&1) extra1-=2;
        if(extra2&1) extra2-=2;
        ans1+=extra1;
        ans2+=extra2;
        LL mx=0;
        if(f1>=0) mx=max(mx,ans1);
        if(f2>=0) mx=max(mx,ans2);
        cout<<mx<<endl;
    }
    return 0;
}
