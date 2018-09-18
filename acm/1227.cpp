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
    int t;
    cin>>t;
    int test=1;
    while(t--){
        int n,p,q;
        cin>>n>>p>>q;
        vector<int>v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        sort(v.begin(),v.end());
        int sum=0;
        int cnt=0;
        for(int i=0;i<min(n,p);i++){
            if(sum+v[i]>q) break;
            sum+=v[i];
            cnt++;
        }
        cout<<"Case "<<test++<<": "<<cnt<<endl;
    }
    return 0;
}
