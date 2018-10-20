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

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<string,double>mp;
        double ansfinal=0;
        while(n--)
        {
            string s;
            cin>>s;
            if(mp.find(s)!=mp.end()) ansfinal+=mp[s];
            else{
                double ans=0;
                for(int i=0;i<s.length();i++)
                {
                    if(!i) ans+=0.2;
                    else{
                        if((s[i]=='d' || s[i]=='f') && (s[i-1]=='d' || s[i-1]=='f')) ans+=0.4;
                        else if((s[i]=='j' || s[i]=='k') && (s[i-1]=='j' || s[i-1]=='k')) ans+=0.4;
                        else ans+=0.2;
                    }
                }
                ansfinal+=ans;
                mp[s]=ans/2.0;
            }
        }
        cout<<ansfinal*10<<endl;
    }
    return 0;
}

