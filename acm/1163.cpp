/*

SOLUTION IDEA:
--------------

 Let, the given number is X = A - B. Here, B = A/10.
So, A - A/10 = X
    A - (A-A%10)/10 = X
    10A - A + (A%10) = 10X
    9A = 10X - K , let K = A%10
    A = (10X - K)/9
    A = X + (X - K)/9
For K equals to 0 to 9, if (X - K)%9 = 0, then A would be a solution.
If we get a solution for K = 0, then we would also get a solution for
K = 9 in this case. That means, if X%9 = 0, then there exists two solution.

*/
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

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<"Case "<<test++<<":";
        for(ll i=9;i>=0;i--)
        {
            if((n-i)%9==0) cout<<" "<<n+(n-i)/9ll;
        }
        cout<<endl;
    }
    return 0;
}

