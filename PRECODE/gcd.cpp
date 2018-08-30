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

int gcd_loop(int a,int b)
{
    if(a==0) return b;
    else if(b==0) return a;
    int t;
    for(;a!=0;){
        t=a;
        a=b%a;
        b=t;
    }
    return b;
}

int gcd_rec(int a,int b){ ///a>b
    if(b==0) return a;
    return gcd(b,a%b);
}
