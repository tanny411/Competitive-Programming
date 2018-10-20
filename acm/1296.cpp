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
///https://translate.google.com/translate?hl=en&sl=zh-CN&u=http://www.voidcn.com/article/p-gdnqkpvv-qg.html&prev=search
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=0;
        while(n--)
        {
            int x;
            cin>>x;
            while(x&1) x/=2;
            ans^=x/2;
        }
        if(ans) cout<<"Case "<<test++<<": Alice\n";
        else cout<<"Case "<<test++<<": Bob\n";
    }
    return 0;
}

