#include<bits/stdc++.h>
#define pii pair<int,int>
#define fs first
#define sc second
#define CIN ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
bool cmp(pii a,pii b){
    if(a.fs==b.fs) return a.sc<b.sc;
    else return a.fs<b.fs;
}
int main()
{
    int n;
    cin>>n;
    vector<pii>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].fs>>v[i].sc;
    }
    if(n==2){
        cout<<max(v[0].sc-v[0].fs,v[1].sc-v[1].fs)<<endl;
        return 0;
    }
    sort(v.begin(),v.end(),cmp);
    int st=v[0].fs,en=v[0].sc;
    int sid=0,eid=0;
    int skip=0;
    for(int i=1;i<n;i++){
        if(v[i].fs<=en){
            sid=i;
            if(v[i].sc<=en) {
                en=v[i].sc;
                eid=i;
            }
        }
        else if(!skip) skip=1;
        else{
            cout<<0;
            return 0;
        }
    }
    if(skip) {cout<<v[eid].sc-v[sid].fs<<endl; return 0;}
    int ans=-1,x=sid,y=eid;
    st=v[1].fs,en=v[1].sc;
    sid=1,eid=1;
    for(int i=2;i<n;i++){
        if(v[i].fs<=en){
            sid=i;
            if(v[i].sc<=en) {
                en=v[i].sc;
                eid=i;
            }
        }
        else {
            ans=0;
            break;
        }
    }
    if(ans==-1) ans=v[eid].sc-v[sid].fs;
    st=-1;en=1000000004;
    sid=-1;eid=-1;
    for(int i=0;i<n;i++){
        if(i==x) continue;
        if(v[i].fs<=en){
            sid=i;
            if(v[i].sc<=en) {
                en=v[i].sc;
                eid=i;
            }
        }
    }
    ans=max(ans,v[eid].sc-v[sid].fs);
    st=-1;en=1000000004;
    sid=-1;eid=-1;
    for(int i=0;i<n;i++){
        if(i==y) continue;
        if(v[i].fs<=en){
            sid=i;
            if(v[i].sc<=en) {
                en=v[i].sc;
                eid=i;
            }
        }
    }
    cout<<max(v[eid].sc-v[sid].fs,ans)<<endl;
    return 0;
}
