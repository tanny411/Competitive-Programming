
#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define LLU unsigned long long

#define fs first
#define sc second

using namespace std;
vector<ll>v,in,tpow,cum,cumrem,flag;
vector<int>mp;
int counter;
int rec(int now,int m,int sz)
{
    if(flag[now]==counter) return 0;
    flag[now]=counter;
    int ret=0;
    for(int i=0;i<m;i++)
    {
        if(!v[i]) continue;
        ll nnow=(((now+i)%m)*tpow[sz])%m;
        ll nneed=((m-nnow)%m+m)%m;
        if(v[nneed]>0 || rec(nnow,m,sz)) {
            ret=1;
            break;
        }
    }
    return mp[now]=ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll m,n=s.length();
        cin>>m;

        v=vector<ll>(m+4);
        mp=vector<int>(m+4,-1);
        flag=vector<ll>(m+4);
        in=vector<ll>(n+4);
        tpow=vector<ll>(n+4);
        cum=vector<ll>(n+4);
        cumrem=vector<ll>(n+4);

        ///precalc
        tpow[0]=1;
        for(int i=1;i<n;i++)
        {
            tpow[i]=(tpow[i-1]*10ll)%m;
        }

        ///do
        ll sum=0;
        ll sumrem=0;
        for(int i=n-1,p=0,pr=-1 ;i>=0; i--,p++,pr++)
        {
            ll num=(s[i]-'0');
            sum=(sum+num*tpow[p])%m;
            if(pr>=0) sumrem=(sumrem+num*tpow[pr])%m;

            cum[i]=sum;
            cumrem[i]=sumrem;
        }

        in[n-1]=sumrem%m;
        v[sumrem%m]++;

        for(int i=n-2;i>=0;i--)
        {
            in[i]=(cum[i+1]+sumrem-cumrem[i])%m;
            in[i]=(in[i]+m)%m;
            v[in[i]]++;
        }

        ///answer
        ll cnt=0;
        counter=1;

        for(int i=0;i<n;i++)
        {
            int now=in[i];
            now=(now*tpow[n-1])%m;
            now=(now+m)%m;
            ll need=(m-now)%m;
            need=(need+m)%m;

            if(v[need]>0) {cnt++;continue;}

            //continue;

            if(mp[now]!=-1)
            {
                cnt+=mp[now];
                continue;
            }
            counter++;
            int x=rec(now,m,n-1);
            mp[now]=x;
            if(x) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}


