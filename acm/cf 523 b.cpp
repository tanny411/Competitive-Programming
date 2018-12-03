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
    int n,m;
    cin>>n>>m;
    vector<int>v;
    LL cnt=0,sum=0,incnt=0;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        v.pb(x);
        sum+=x;
    }
    sort(v.rbegin(),v.rend());
    v.pb(0);
    for(int i=0;i<n;i++)
    {
        if(v[i]<=0) break;
        int s=v[i]-v[i+1];
        if(s>0){
            cnt+=s;
            incnt++;
        }
        else{
            incnt++;
            cnt++;
            v[i+1]=v[i]-1;
        }
    }
    cnt+=(n-incnt);
    cout<<sum-cnt<<endl;
    return 0;
}

