#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<double>mean(n),vals,cum;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        double sum=0;
        for(int j=0;j<m;j++){
            double x;
            cin>>x;
            vals.push_back(x);
            sum+=x;
        }
        mean[i]=sum/(1.0*m);
    }
    sort(vals.begin(),vals.end());
    cum=vals;
    for(int i=1;i<cum.size();i++){
        cum[i]+=cum[i-1];
    }
    double mn=-1;
    int sz=vals.size();
    for(int i=0;i<n;i++){
        int in=lower_bound(vals.begin(),vals.end(),mean[i])-vals.begin();
        double ans=0;
        if(in>0) ans+=in*mean[i]-cum[in-1];
        if(in<sz) ans+=cum[sz-1]-(in>0?cum[in-1]:0.0) - 1.0*(sz-in)*mean[i];
        if(mn==-1) mn=ans;
        else mn=min(mn,ans);
    }
    cout<<fixed<<setprecision(20)<<mn<<endl;
    return 0;
}
