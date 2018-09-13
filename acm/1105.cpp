#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define LLU unsigned long long

#define fs first
#define sc second
#define huh 50
///ios_base::sync_with_stdio(false);

using namespace std;

int main()
{
    //freopen("out.txt","w",stdout);
    ll fib[huh];
    fib[0]=1;
    fib[1]=2;
    for(int i=2;i<huh;i++) fib[i]=fib[i-1]+fib[i-2];
    int t;
    cin>>t;
    int test=1;
    while(t--){
        int n;
        cin>>n;
        int ase=0;
        string str;
        for(int i=huh-1;i>=0;i--){
            if(n>=fib[i]){
                n-=fib[i];
                str+='1';
                ase=1;
            }
            else if(ase) str+='0';
        }
        cout<<"Case "<<test++<<": "<<str<<endl;
    }
    return 0;
}
/**
1
665493810
ans:101010000001010001001010001000100100100100
*/
