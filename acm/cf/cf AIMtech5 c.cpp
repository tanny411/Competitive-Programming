#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>
#define INTMAX 1<<30
#define MOD 1000000007

#define fs first
#define sc second

using namespace std;

bool cmp(ppp a,ppp b){
    if(a.fs.fs==b.fs.fs) return a.fs.sc<b.fs.sc;
    else return a.fs.fs<b.fs.fs;
}
int main()
{
    int n;
    cin>>n;
    vector<ppp>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].fs.fs>>v[i].fs.sc>>v[i].sc.fs>>v[i].sc.sc;
    }
    sort(v.begin(),v.end(),cmp);
    int r=v[0].sc.fs,u=v[0].sc.sc;
    int l=v[0].fs.fs,d=v[0].fs.sc;
    int skip=0;
    int noh=0;
    for(int i=1;i<n;i++)
    {
        if( (v[i].fs.fs>r || v[i].fs.sc>u)){
            if(skip) {
                noh=1;
                break;
            }
            else skip=1;
        }
        else{
            r=min(r,v[i].sc.fs);
            u=min(u,v[i].sc.sc);
        }
    }
    if(!noh) cout<<r<<" "<<u<<endl;
    else{
        r=v[1].sc.fs;
        u=v[1].sc.sc;
        for(int i=2;i<n;i++)
        {
            r=min(r,v[i].sc.fs);
            u=min(u,v[i].sc.sc);
        }
        cout<<r<<" "<<u<<endl;
    }
    return 0;
}
