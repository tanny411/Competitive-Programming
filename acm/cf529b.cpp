#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

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
    int mx=-(1<<30),mn=1<<30,scmx,scmn;
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    mx=v[n-1];
    scmx=v[n-2];
    mn=v[0];
    scmn=v[1];
    cout<<min(mx-mn,min(mx-scmn,scmx-mn))<<endl;
    return 0;
}