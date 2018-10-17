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

unordered_map<string,bool>mp;
bool rec(string s,int sum)
{
    ///tle
    if(mp.find(s)!=mp.end()) return mp[s];
    for(int i=0;i<s.length();i++)
    {
        int x=sum-s[i]-'0';
        if(x%3==0){
            string temp=s;
            temp.erase(temp.begin()+i);
            if(!rec(temp,x)) return mp[s]=true;
        }
    }
    return mp[s]=false;
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
        int ara[20];
        memset(ara,0,sizeof ara);
        int n=s.size(),sum=0;
        for(int i=0;i<n;i++)
        {
            int temp=s[i]-'0';
            sum+=temp;
            ara[temp]++;
        }
        int S=1;
        if(sum%3==0)
        {
            if((ara[3]+ara[6]+ara[9])%2==0) S=0;
        }
        else if(sum%3==1)
        {
            if(ara[1]||ara[4]||ara[7]){
                if((ara[3]+ara[6]+ara[9])%2==1) S=0;
            }
            else S=0;
        }
        else if(sum%3==2)
        {
            if(ara[2]||ara[5]||ara[8]){
                if((ara[3]+ara[6]+ara[9])%2==1) S=0;
            }
            else S=0;
        }
        if(S) cout<<"Case "<<test++<<": S\n";
        else cout<<"Case "<<test++<<": T\n";
    }
    return 0;
}

