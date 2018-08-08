#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
bool cmp(pii a,pii b){
    return a.fs==b.fs?a.sc<b.sc:a.fs>b.fs;
}
int main()
{
    int n;
    cin>>n;
    vector<pii>v(n);
    for(int i=0;i<n;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        v[i]={a+b+c+d,i};
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++){
        if(v[i].sc==0) {cout<<i+1<<endl;return 0;}
    }
    return 0;
}

