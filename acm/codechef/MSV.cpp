#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;
#define mx 1000001
vector<int>divs(mx,-1);
map<int,int>vals,vv;
/*
void init(){
    for(int i=2;i<mx;i+=2){
        divs[i]=2;
    }
    int sqrt(mx);
    for(ll i=3;i<=sqrt;i+=2){
        if(divs[i]==-1){
            for(ll j=i;j<mx;j+=i){
                divs[j]=i;
            }
        }
    }
}
int prime_factorization(int x){
    while(x>1){
        int dv=divs[x];
        x/=dv;
        //dv
    }
}
*/

void look(int x){
    // cout<<x<<": ";
    int k=sqrt(x);
    for(int i=1;i<=k;i++){
        if(x%i) continue;
        if(vals.count(i)){
            vv[i]++;
            // cout<<" ("<<i<<","<<vals.count(i)<<")";
        }
        if(i!=(x/i) && vals.count(x/i)) {
            vv[x/i]++;
            // cout<<" ("<<x/i<<","<<vals.count(x/i)<<")";
        }
    }
    // cout<<endl;
}

int main(){
    int cas=1,t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        vv.clear();
        vals.clear();
        int ans=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        for(int i=n-1;i>=0;i--){
            int x=v[i];
            look(x);
            //no need to save differently for different positions of the same number
            //the later position will always have more multiples to its left
            vals[x]++;
        }
        for(int i=0;i<n;i++) 
            ans=max(ans,vv[v[i]]); //, cout<<" "<<vv[v[i]];
        cout<<ans<<endl;

    }

    return 0;
}