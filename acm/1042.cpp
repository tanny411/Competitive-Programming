#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define llu unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int next_greater(int n)
{
    int a=(~n)+1; //-n
    int t=a&n;
    int x=n+t;
    int y=x^n;
    y=y/t;
    y=y>>2;
    return x|y;
}
int main()
{
    int t;
    cin>>t;
    int test=1;
    while(t--)
    {
        int x;
        cin>>x;
        cout<<"Case "<<test++<<": "<<next_greater(x)<<endl;
    }
    return 0;
}
