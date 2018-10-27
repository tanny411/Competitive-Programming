#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define LLU unsigned long long

#define fs first
#define sc second
/**
Given Number P = 25, i = 2 , j= P/i = 12
From above calculation, we can find out two relations
First Relation
2+3+4+5+6+7+8+9+10+11+12
= 1+2+3+4+5+6+7+8+9+10+11+12-1
= j*(j+1)/2 - (i-1)*(i-1+1)/2
= j*(j+1)/2 - (i-1)*(i)/2
= (j^2+j - i^2 + i)/2
= ((j-i)(j+i)+(j+i))/2
= ((j+i)(j-i+1))/2  (General Form)
= (14 * 11 )/2 = 77

Second Relation
2x10 = i*(j-i)  (General Form)
     = 20

Again
 i  = 3 ,  j = P/i = 8

First Relation
3+4+5+6+7+8
= (1+2+3+4+5+6+7+8) - (1+2)
= (j*(j+1)/2 - (i-1)*(i-1+1)/2
= ((j+i)(j-i+1))/2  (General Form)
= (11 * 6 )/2 = 33

Second Relation
3x5 = i*(j-i)
    = 15

Again
 i  = 4 ,  j = P/i = 6

First Relation
4+5+6
= (1+2+3+4+5+6) - (1+2+3)
= (j*(j+1)/2 - (i-1)*(i-1+1)/2
= ((j+i)(j-i+1))/2  (General Form)
= (10 * 3 )/2 = 15

Second Relation
4x2 = i*(j-i)
    = 8

Again
 i  = 5 ,  j = P/i = 5

First Relation
5
= (1+2+3+4+5) - (1+2+3+4)
= (j*(j+1)/2 - (i-1)*(i-1+1)/2
= ((j+i)(j-i+1))/2  (General Form)
= (10 * 1 )/2 = 5

Second Relation
5x0 = i*(j-i)
    = 0

SUM = 77+20+33+15+15+8+5+0 = 173
**/
using namespace std;
ll solve(ll n)
{
    ll ans=0;
    for(ll i=2;i*i<=n;i++)
    {
        ll j=n/i;
        ans+=(j+i)*(j-i+1)/2ll;
        ans+=i*(j-i);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<"Case "<<test++<<": "<<solve(n)<<endl;
    }
    return 0;
}

