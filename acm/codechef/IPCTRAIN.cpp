#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;
class dt{
public:
    long long d,t,s;
    dt(){}
    dt(long long d,long long t,long long s):d(d),t(t),s(s){}
    bool operator < (const dt a) const{
        return s>a.s;
    }
};
vector<dt>v;
vector<int>day;
vector<int>flag;
long long numDay,d;
int give(int startDay){
    if(startDay==d) return d;
    if(numDay==0) return startDay;

    if(flag[startDay]==0){
        flag[startDay]=1;
        numDay--;
    }
    return day[startDay]=give(day[startDay]);
}
/*
1
2 3
1 2 100
2 2 100
*/
int main(){
    int cas=1,t;

    cin>>t;
    while(t--){
        int n;
        cin>>n>>d;
        day = vector<int>(d);
        flag = vector<int>(d);
        v = vector<dt>(n);
        for(int i=0;i<d;i++) day[i]=i+1;
        for(int i=0;i<n;i++){
            cin>>v[i].d>>v[i].t>>v[i].s;
            v[i].d--;
        }
        sort(v.begin(),v.end());
        long long ans=0;
        for(int i=0;i<n;i++){
            numDay = v[i].t;
            give(v[i].d);
            ans+=numDay*v[i].s;
        }
        cout<<ans<<endl;
    }

    return 0;
}