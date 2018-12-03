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
    int n,k;
    cin>>n>>k;
    int red=2*n;
    int green=5*n;
    int blue=8*n;
    red=ceil(red/(1.0*k));
    green=ceil(green/(1.0*k));
    blue=ceil(blue/(1.0*k));
    cout<<red+green+blue<<endl;
    return 0;
}

