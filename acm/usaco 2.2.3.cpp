/*
ID: aysha.k1
LANG: C++11
TASK: runround
*/
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
bool is(LL p)
{
    int dig[10]={0};
    vector<int>v;
    while(p)
    {
        if(dig[p%10] || p%10==0) return 0;
        dig[p%10]=1;
        v.pb(p%10);
        p/=10;
    }
    reverse(v.begin(),v.end());
    int cnt=0,siz=v.size();
    int i=0;
    int x=v[i];
    int fl[v.size()];
    memset(fl,0,sizeof fl);
    while(1)
    {
        if(fl[i]==0) cnt++;
        else return 0;
        fl[i]=1;
        i=(i+x)%siz;
        x=v[i];
        if(i==0 && cnt==siz) return 1;
        if(cnt==siz) return 0;
    }
}
int main()
{
    freopen("runround.in","r",stdin);
    freopen("runround.out","w",stdout);
    int n;
    cin>>n;
    for(int i=n+1;;i++)
    {
        //cout<<i;
        if(is(i))
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}

