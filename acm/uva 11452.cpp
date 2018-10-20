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
int periodKoto(string pat,int m)
{
    vector<int>lps(m);
    lps[0]=0;
    int len=0;
    int i=1;
    while(i<m)
    {
        if(pat[len]==pat[i]) lps[i]=++len,i++;
        else if(len!=0) len=lps[len-1];
        else lps[i]=0,i++;
    }
    for(int i=m-1;i>=0;i--)
    {
        int p=i+1-lps[i];
        if((i+1)%p==0)
        {
            int num=(i+1)/p;
            if(num%2==0) return (num/2)*p;
        }
    }
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
        int n=s.length();
        int p=periodKoto(s,n);
        int pl=n-p*2;
        for(int i=0;i<8;i++,pl=(1+pl)%p)
        {
            cout<<s[pl];
        }
        cout<<"...\n";
    }
    return 0;
}

