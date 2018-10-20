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

void computeLPS(string pat,int m,vector<int>&lps)
{
    lps[0]=0;
    int len=0;
    int i=1;
    while(i<m)
    {
        if(pat[len]==pat[i]) lps[i]=++len,i++;
        else if(len!=0) len=lps[len-1];
        else lps[i]=0,i++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        string t,p;
        cin>>t>>p;
        int n=t.size();
        int m=p.size();
        int siz=n+m+1;
        string s=p+"#"+t;
        reverse(p.begin(),p.end());
        reverse(t.begin(),t.end());
        string sr=p+"#"+t;
        vector<int>lps(siz),lpsr(siz);
        computeLPS(s,siz,lps);
        computeLPS(sr,siz,lpsr);
        ll ans=0;
        vector<ll>ans1(siz+2),ans2(siz+2);
        for(int i=0;i<siz;i++)
        {
            if(lps[i]) ans1[i]+=ans1[lps[i]-1];
            if(lpsr[i]) ans2[i]+=ans2[lpsr[i]-1];
            if(lps[i] && lps[i]<m) ans1[i]++;
            if(lpsr[i] && lpsr[i]<m) ans2[i]++;
        }
        //for(int i=0;i<siz;i++) cout<<" "<<ans1[i]; cout<<endl;
        for(int i=m+1,go=2;i<siz-1;i++,go++)
        {
            ans+=1ll*ans1[i]*ans2[siz-go];
        }
        cout<<"Case "<<test++<<": "<<ans<<endl;
    }
    return 0;
}

