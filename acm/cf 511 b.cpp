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
    int n;
    cin>>n;
    int mx=0;
    while(n--){
        int x,y;
        cin>>x>>y;
        mx=max(mx,x+y);
    }
    cout<<mx<<endl;
    return 0;
}
