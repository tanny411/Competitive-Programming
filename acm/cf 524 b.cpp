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
LL fun(LL n)
{
    LL even=n/2LL;
    even=even*(even+1);
    even*=2LL;
    return even-(n*(n+1)/2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--)
    {
        LL l,r;
        cin>>l>>r;
        cout<<fun(r)-fun(l-1)<<endl;
    }
    return 0;
}

