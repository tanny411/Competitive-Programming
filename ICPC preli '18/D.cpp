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

using namespace std;
int is_prime(int n)
{
    int i,root;
    if(n<2) return 0;
    else if(n==2) return 1;
    else if(n%2==0) return 0;
    else{
        root=sqrt(n);
        for(int i=3;i<=root;i+=2){
            if(n%i==0) return 0;
        }
        return 1;
    }
}
void sieve()
{
    p.pb(2);
    for()
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    for(int i=1;i<=1000000;i++)
    {
        if(is_prime(i))
        {
            ll a=i;
            while(a){
                if(a%10!=2 && a%10!=3 && a%10!=5 && a%10!=7) break;
                a/=10;
            }
            if(!a) cout<<i<<endl;
        }
    }
    return 0;
}
