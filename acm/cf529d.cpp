#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>

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

int ara[200005][2];

int main()
{
    int n;
    cin>>n;
    int i=1;
    for(;i<=n;i++)
    {
        cin>>ara[i][0]>>ara[i][1];
    }
    if(n==3)
    {
        cout<<"1 2 3\n";
        return 0;
    }
    i=1;
    for(int done=0;done<n;done++){
        cout<<i<<" ";
        if(ara[ ara[i][0] ][0]==ara[i][1] || ara[ ara[i][0] ][1]==ara[i][1]) {
            i=ara[i][0];
        }
        else if(ara[ ara[i][1] ][0]==ara[i][0] || ara[ ara[i][1] ][1]==ara[i][0]) {
            i=ara[i][1];
        }
    }
    return 0;
}