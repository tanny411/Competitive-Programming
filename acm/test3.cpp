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
long long bg(int base,int pow,int m)
{
    if(pow==0) return 1;
    long long x=bg(base,pow/2,m);
    x=(x*x)%m;
    if(pow&1) x=(base*x)%m;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cout<<bg(3,12,11);
    return 0;
}

