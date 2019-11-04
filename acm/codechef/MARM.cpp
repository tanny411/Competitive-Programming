#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;

    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<int>a(n),b(n),c(n),ans(n),ori(n);
        vector<vector<int>>v(3,vector<int>(n));
        for(int i=0;i<n;i++) {
            cin>>ori[i];
            b[i]=ori[i];
        }

        ll dv = k%n;
        ll md = k/n; md = md%3;
        
        for(int i=0;i<n;i++) {
            b[i]=b[i]^b[n-i-1];
            c[i]=b[i];
        }
        for(int i=0;i<n;i++) {
            c[i]=c[i]^c[n-i-1];
            a[i]=c[i];
        }
        for(int i=0;i<n;i++) {
            a[i]=a[i]^a[n-i-1];
        }

        v[0]=b;v[1]=c;v[2]=a;
        
        for(int i=0;i<dv;i++){
            ans[i]=v[md][i];
        }

        int mdd;
        mdd = (md+3-1)%3;
        if(k<n) v[2]=ori;

        for(int i=dv;i<n;i++){
            ans[i]=v[mdd][i];
        }
        for(int i=0;i<n;i++){
            if(i) cout<<" ";
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}