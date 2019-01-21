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

int main()
{
    int n,k;
    cin>>n>>k;
    int temp=n;
    vector<int>v;
    int cnt=0;
    while(temp)
    {
        if(temp&1) v.pb(cnt);
        cnt++;
        temp/=2;
    }
    /*for(int i=0;i<v.size();i++)
    {
        cout<<(1<<v[i])<<" ";
    }*/
    if(k>n || k<v.size()) cout<<"NO\n";
    else if(k==n){
        cout<<"YES\n";
        while(n--) cout<<1<<" ";
    }
    else if(k==v.size())
    {
        cout<<"YES\n";
        for(int i=0;i<v.size();i++)
        {
            cout<<(1<<v[i])<<" ";
        }
    }
    else{
        int rem=k-v.size();
        cout<<"YES\n";
        for(int i=0;i<v.size() && rem;i++)
        {
            while(v[i]>0 && rem){
                v[i]--;
                v.pb(v[i]);
                rem--;
            }
        }
        for(int i=0;i<v.size();i++)
        {
            cout<<(1<<v[i])<<" ";
        }
    }
    return 0;
}