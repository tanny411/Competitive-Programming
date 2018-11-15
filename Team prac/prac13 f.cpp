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
    int n;
    cin>>n;
    vector<int>v(n);
    map<int,int>mp;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(i) v[i]+=v[i-1];
        mp[v[i]]=1;
    }
    sum=v[n-1];
    if(sum%3){
        cout<<"0\n";
        return 0;
    }
    int cnt=0;
    sum/=3;
    for(int i=0;i<n;i++)
    {
        if(mp.count(v[i]+sum) && mp.count(v[i]+sum+sum)) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}

