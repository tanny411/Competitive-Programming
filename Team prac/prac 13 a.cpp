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
    int t,test=1;
    int a,b,c;
    cin>>a>>b>>c;
    int o=0,z=0;
    if(a) o++; else z++;
    if(b) o++; else z++;
    if(c) o++; else z++;
    if(o==1)
    {
        if(a) cout<<"A\n";
        else if(b) cout<<"B\n";
        else cout<<"C\n";
    }
    else if(z==1)
    {
        if(!a) cout<<"A\n";
        else if(!b) cout<<"B\n";
        else cout<<"C\n";
    }
    else cout<<"*\n";
    return 0;
}

