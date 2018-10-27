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

#define mx 50003
int flag[mx];
vector<int>prime;
void sieve(){
    prime.pb(2);
    for(int i=3;i<mx;i+=2)
    {
        if(flag[i]==0)
        {
            prime.pb(i);
            for(ll j=1ll*i*i;j<mx;j+=(i+i))
            {
                flag[j]=1;
            }
        }
    }
}
int segment[100005];
int segmentSieve(int a,int b)
{
    memset(segment,0,sizeof segment);
    if(a==0) segment[0]=segment[1]=1;
    else if(a==1) segment[0]=1;
    int sz=prime.size();
    for(int i=0;i<sz && prime[i]*prime[i]<=b;i++)
    {
        ll st=ceil(a/(1.0*prime[i]));
        //cout<<prime[i]<<" "<<st<<endl;
        if(st<=1) st=2*prime[i];
        else st*=prime[i];

        for(ll j=st;j<=b;j+=prime[i]) segment[j-a]=1;
    }
    int sum=0;
    for(int i=0;i<=b-a;i++)
    {
        //if(!segment[i]) cout<<" "<<i+a;
        sum+=(!segment[i]);
    }
    //cout<<endl;
    return sum;
}
int main()
{
    sieve();
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<"Case "<<test++<<": "<<segmentSieve(a,b)<<endl;
    }
    return 0;
}

