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
vector<int>lps;
void computeLPS(string pat,int m)
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
        string s;
        cin>>s;
        int n=s.length();
        lps=vector<int>(n);
        computeLPS(s,n);
        int k=n-lps[n-1];
        if(n%k!=0) cout<<n<<endl;
        else cout<<k<<endl;
        if(t) cout<<endl;
    }
    return 0;
}

