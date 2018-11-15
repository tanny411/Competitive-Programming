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
    while(cin>>n>>k)
    {
        string s;
        cin>>s;
        k%=3;
        if(k==0) cout<<s<<endl;
        else{
            int q=n/4;
            string a,b,c,d;
            for(int i=0;i<q;i++) a+=s[i];
            for(int i=q;i<q+q;i++) b+=s[i];
            for(int i=q+q;i<3*q;i++) c+=s[i];
            for(int i=3*q;i<n;i++) d+=s[i];
            if(k==1) cout<<a<<d<<b<<c<<endl;
            if(k==2) cout<<a<<c<<d<<b<<endl;
        }
    }


    return 0;
}

