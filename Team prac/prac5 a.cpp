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
        string s;
        cin>>s;
        int cnt=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            int j=(i+1)%n;
            if(s[i]!=s[j]) cnt++;
        }
        if(cnt<=2) cout<<"uniform\n";
        else cout<<"non-uniform\n";
    }
    return 0;
}

