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

///ios_base::sync_with_stdio(false);

using namespace std;

int main()
{
    string s,t;
    while(cin>>s>>t)
    {
        int n=s.length();
        int m=t.length();
        if(n>m) cout<<"No\n";
        else{
            int start=0,ase=0;
            for(int i=0;i<m;i++)
            {
                if(t[i]==s[start]) start++;
                if(start==n){
                    ase=1;
                    break;
                }
            }
            if(ase) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }

    return 0;
}
