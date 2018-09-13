#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n,a,b;
        cin>>n>>a>>b;
        ll cnt=n;
        ll temp=a;
        int oa=0,ob=0;
        while(cnt--){
            oa+=(temp%2==1);
            temp/=2;
        }
        cnt=n;
        temp=b;
        while(cnt--){
            ob+=(temp%2==1);
            temp/=2;
        }
        int za=n-oa;
        int zb=n-ob;
        ll sum=0;
        int x=min(za,ob);
        za-=x;
        ob-=x;
        n-=x;
        sum=(sum<<x)|((1<<x)-1);
        x=min(zb,oa);
        zb-=x;
        oa-=x;
        n-=x;
        sum=(sum<<x)|((1<<x)-1);
        sum<<=n;
        cout<<sum<<endl;
    }
    return 0;
}
