#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define inf 1<<30
#define MOD 1000000007

#define LL long long
#define LLU unsigned long long

#define fs first
#define sc second

using namespace std;

int main()
{
    ///no solve
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n,x,y,d;
        cin>>n>>x>>y>>d;
        int mn=inf;
        int xx=x%d;
        int yy=y%d;
        if(abs(xx)==abs(yy) && abs(xx)<=n) mn=abs(y-xx)/d + abs(x-xx)/d;
//        for(int i=1;i<=n;i++)
//        {
//            if(abs(y-i)%d==0 && abs(x-i)%d==0) mn=min(mn,abs(y-i)/d + abs(x-i)/d);
//        }
        if(abs(y-1)%d==0 && abs(x-1)%d!=0) mn=min(mn,abs(y-1)/d + abs(x-1)/d + 1);
        if(abs(y-n)%d==0 && abs(x-n)%d!=0) mn=min(mn,abs(y-n)/d + abs(x-n)/d + 1);
        if(mn==inf) mn=-1;
        cout<<mn<<endl;
    }
    return 0;
}

