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
    string s;
    cin>>s;
    int ase=0;
    for(int i=0;i<n;i++) if(s[i]=='8')ase++;
    if(ase==0) {cout<<0<<endl; return 0;}
    int ans=0;
    n-=ase;
    while(ase>0){
        if(n>=10) {
            ase--;
            n-=10;
            ans++;
        }
        else if(ase-1+n>=10){
            ase-=(1+10-n);
            n=0;
            ans++;
        }
        else break;
    }
    cout<<ans<<endl;
    return 0;
}

