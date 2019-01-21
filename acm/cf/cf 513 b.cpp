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

int main()
{
    ios_base::sync_with_stdio(false);
    ll x;
    cin>>x;
    if(x<10) {
        cout<<x<<endl;
        return 0;
    }
    ll sum=0,first=1;
    while(x)
    {
        ll d=(x%10);
        x/=10;
        if(x==0){
            if(first==1) sum+=d;
            else sum+=d-1;
        }
        else if(first==1){
            if(d==9) sum+=9;
            else {sum+=d+10;first=0;}
        }
        else {
            sum+=d+9;
            first=0;
        }
    }
    cout<<sum<<endl;
    return 0;
}

