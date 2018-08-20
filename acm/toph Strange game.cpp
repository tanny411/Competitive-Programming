#include<bits/stdc++.h>
#define pb push_back

using namespace std;

int main()
{
    int x,y,k,t,test=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        int mn=1<<30;
        int mx=-1;
        long long sq=0;
        long long  sum=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            mn=min(mn,v[i]);
            mx=max(mx,v[i]);
            sq+=v[i]*v[i];
            sum+=v[i];
        }
        int ok=-1;
        long long ans=1<<30;
        for(int i=mn;i<=mx;i++){
            long long temp=n*i*i-2*i*sum;
            if(temp<ans){
                ans=temp;
                ok=i;
            }
        }
        cout<<"Case "<<test++<<": "<<ok<<" "<<ans+sq<<endl;
    }


    return 0;
}

