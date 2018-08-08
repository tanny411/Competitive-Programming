#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[50][50];

ll rec(int len,int pos,int tight,int ok,string s)
{
    if(pos>=ceil(len/2.0))
    {
        if(tight==0 || (tight && ok)) return 1ll;
        else return 0ll;
    }
    if(!tight && dp[len][pos]!=-1) return dp[len][pos];
    ll ret=0;
    int lim=tight?(s[pos]-'0'):9;
    for(int i=0;i<=lim;i++)
    {
        if(i==0 && pos==0) continue;
        //if(i!=0 && i!=8 && i!=1) continue;
        int newtight=i<lim?0:tight;
        int newok=ok?(s[len-pos-1]-'0')>=i:(s[len-pos-1]-'0')>i;
        ret+=rec(len,pos+1,newtight,newok,s);
    }
    if(tight==0) dp[len][pos]=ret;
    return ret;
}

ll pal(string s)
{
    int l=s.length();
    ll ans=0;
    for(int i=1;i<=l;i++)
    {
        ans+=rec(i,0,i==l,1,s);
    }
    return ans;
}

int ispali(string s)
{
    int l=s.length();
    int m=l/2;
    for(int i=0;i<=m;i++)
    {
        if(s[i]!=s[l-i-1] || (s[i]!='1' && s[i]!='0' && s[i]!='8')) return 0ll;
    }
    return 1ll;
}

int main()
{
    memset(dp,-1,sizeof dp);

    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        //cout<<"        "<<pal(b)<<" "<<pal(a)<<" "<<ispali(a)<<endl;
        cout<<pal(b)-pal(a)+ispali(a)<<endl;
    }
    return 0;
}
