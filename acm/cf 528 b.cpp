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
    int mn=1<<30;
    for(int m=1;m<k;m++)
    {
        if(n%m==0)
        {
            int hu=n/m;
            mn=min(hu*k+m,mn);
        }
    }
    cout<<mn<<endl;
    //for(int i=k;i<=110;i++) cout<<i%k<<" ";
    return 0;
}

