#include<bits/stdc++.h>
#define fs first
#define sc second
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int> >v(n);
    int cnt=0;
    for(int i=0;i<n;i++) cin>>v[i].fs>>v[i].sc;
    for(int i=0;i<n;i++){
        int type[4];
        memset(type,0,sizeof type);
        for(int j=0;j<n;j++){
            if(v[i].fs==v[j].fs && v[i].sc>v[j].sc) type[0]++;
            if(v[i].fs==v[j].fs && v[i].sc<v[j].sc) type[1]++;
            if(v[i].fs>v[j].fs && v[i].sc==v[j].sc) type[2]++;
            if(v[i].fs<v[j].fs && v[i].sc==v[j].sc) type[3]++;
        }
        if(type[0]!=0 && type[1]!=0 && type[2]!=0 && type[3]!=0) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
