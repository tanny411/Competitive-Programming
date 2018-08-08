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

///ios_base::sync_with_stdio(false);

using namespace std;

int main()
{
    ll fact[22];
    fact[0]=fact[1]=1;
    for(int i=2;i<=20;i++) fact[i]=fact[i-1]*i;
    int t;
    int cas=1;
    cin>>t;
    while(t--)
    {
        string s,sans="Impossible";
        int n;
        cin>>s>>n;
        int len=s.length();
        vector<int>f(26);
        for(int i=0;i<len;i++) f[ s[i]-'a' ]++;
        len--;
        for(int i=0;i<26;)
        {
            if(f[i]==0) {i++;continue;}

            f[i]--;

            ll ans=fact[len];
            for(int j=0;j<26;j++)
            {
          //      cout<<" "<<f[j];
                ans/=fact[ f[j] ];
            }
            //cout<<endl;


            if(n>ans)
            {
                n-=ans;
                f[i]++;
                i++;
                //cout<<n<< "  "<<sans<<endl;
                continue;
            }
            if(sans=="Impossible") sans="";
            sans.pb(i+'a');
            len--;
            i=0;
            //cout<<n<< "  "<<sans<<endl;
        }
        cout<<"Case "<<cas++<<": "<<sans<<endl;
    }
    return 0;
}

