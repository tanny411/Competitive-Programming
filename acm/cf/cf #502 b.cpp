#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    long long a1=0,a0=0,bur1=0,bur0=0;
    for(int i=0;i<n;i++){
        if(a[i]=='1') a1++;
        else a0++;
        if(b[i]=='0'){
            if(a[i]=='1') bur1++;
            else bur0++;
        }
    }
    cout<<bur0*a1+bur1*(a0-bur0)<<endl;
    return 0;
}

