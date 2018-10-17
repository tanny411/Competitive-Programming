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
vector<int>prime;
void sieve()
{
    prime.pb(2);
    vector<int>flag(210);
    for(int i=3;i<200;i+=2){
        if(!flag[i]){
            prime.pb(i);
            for(int j=i*i;j<200;j+=(i+i)) flag[j]=1;
        }
    }
}
vector<int>prods;//semiprimes
map<int,int>mp;
bool semiprime(int n)
{
    int cnt=0;
    for(int i=2;i<=n;i++){
        if(n%i==0){
            cnt++;
            n/=i;
            if(n%i==0) return false;
        }
    }
    return cnt==2;
}
bool bruteforce(int n)
{
    for(int i=1;i<=200;i++)
    {
        for(int j=i;j<=200;j++)
        {
            if(i+j==n && semiprime(i) && semiprime(j)) {
                //if(n==25) cout<<"Aiseh "<<i<<" "<<j<<endl;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    sieve();
    int pr=prime.size();
    for(int i=0;i<pr;i++)
    {
        for(int j=i+1;j<pr;j++)
        {
            if(prime[i]*prime[j]<=200) {
                //if(prime[i]*prime[j]==10 || prime[i]*prime[j]==15) cout<<prime[i]*prime[j]<<" AYSHA "<<prods.size()<<endl;
                prods.pb(prime[i]*prime[j]);
            }
            else break;
        }
    }
    int sz=prods.size();
    //cout<<prods.size()<<" < size\n";
    for(int i=0;i<sz;i++)
    {
        for(int j=i;j<sz;j++){
            //if(i==1 && j==24) cout<<prods[i]+prods[j]<<" this?\n";
            if(prods[i]+prods[j]<=200) {
                mp[prods[i]+prods[j]]=1;
                //if(prods[i]+prods[j]==25) cout<<"pailam to\n";
                //if(prods[i]+prods[j]==12) cout<<"culprits"<<prods[i]<<"  "<<prods[j]<<endl;
            }
        }
    }
    int t,test=1;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        if(mp.find(n)!=mp.end()){
            cout<<"YES"<<endl;
            //if(!bruteforce(n)) cout<<n<<" Y-WA\n";
        }
        else {
            cout<<"NO"<<endl;
            //if(bruteforce(n)) cout<<n<<" N-WA\n";
        }
    }
    return 0;
}

