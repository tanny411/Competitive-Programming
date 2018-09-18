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
    int t,test=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x,cnt=0;
        int prev=2;
        for(int i=0;i<n;i++) {
            int x;
            cin>>x;
            cnt+=( (x-prev)/5 + ((x-prev)%5!=0) );
            prev=x;
        }
        cout<<"Case "<<test++<<": "<<cnt<<endl;
    }
    return 0;
}
