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

///

using namespace std;

int flag[3880];
vector<int>prime;
void sieve(int n){
    prime.pb(2);
    for(int i=3;i<=n;i+=2){
        if(flag[i]==0){
            prime.pb(i);
            for(int j=i*i;j<=n;j+=(i+i)){
                flag[j]=1;
            }
        }
    }
}
int cnt[15000003];
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    sieve(3875);
    vector<int>v(n);
    //unordered_map<int,int>cnt;
    int g=0,mx=0;
    for(int i=0;i<n;i++) cin>>v[i], g=__gcd(g,v[i]);
    for(int i=0;i<n;i++){
        int num=v[i]/g;
        for(int j=0;j<prime.size() && prime[j]*prime[j]<=num;j++)
        {
            if(num%prime[j]==0){
                cnt[prime[j]]++;
                mx=max(mx,cnt[prime[j]]);
                while(num%prime[j]==0) num/=prime[j];
            }
        }
        if(num>1) cnt[num]++,mx=max(mx,cnt[num]);
    }
    if(mx==0) cout<<-1<<endl;
    else cout<<n-mx<<endl;
    return 0;
}

