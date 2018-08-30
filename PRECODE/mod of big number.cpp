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
    string str="1792798238231230932";
    int n=str.length();
    int md=1000;
    LL ans=0;
    for(int i=0;i<n;i++){
        ans=(ans*10 + str[i]-'0') % md;
    }
    cout<<ans<<endl;
    return 0;
}
