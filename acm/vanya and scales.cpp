#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>

#define ll long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;
vector<ll>num,a,b;
int f=0;
int siz;

void rec(int i,ll sum)
{
    if(f)a.pb(sum);
    else b.pb(sum);
    if(i==siz) return;
    rec(i+1,sum);
    rec(i+1,sum+num[i]);
    rec(i+1,sum-num[i]);
}

int main()
{
    ll w,m;
    cin>>w>>m;
    if(w==2)
    {
        cout<<"YES";
        return 0;
    }
    ll ww=1;
    while(ww<=m)
    {
        num.pb(ww);
        ww*=w;
    }
    num.pb(ww);
    /*for(int i=0;i<num.size();i++) cout<<" "<<num[i];
    cout<<endl;*/
    siz=num.size()/2;
    rec(0,0);
    f=1;
    siz=num.size();
    rec(siz/2,0);
    /*for(int i=0;i<a.size();i++) cout<<" "<<a[i];
    cout<<endl;
    for(int i=0;i<b.size();i++) cout<<" "<<b[i];
    cout<<endl;*/
    sort(a.begin(),a.end());
    for(int i=0;i<b.size();i++)
    {
        //cout<<b[i]-m<<endl;
        if(binary_search(a.begin(),a.end(),m-b[i])){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}

