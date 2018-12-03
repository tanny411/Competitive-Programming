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

    int n,s;
    cin>>n>>s;
    if(n>=s)
    {
        cout<<1<<endl;
        return 0;
    }
    int cnt=0;
    for(int i=n;i>=1 && s;i--)
    {
        cnt+=s/i;
        s%=i;
    }
    cout<<cnt<<endl;
    return 0;
}

