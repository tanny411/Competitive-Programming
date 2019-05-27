#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;
vector<int>v;
void fn(int x,int sz){
    v=vector<int>(sz);
    for(int i=0;i<sz;i++) v[i]=i*x;
    for(int i=0;i<sz;i++) cout<<" "<<v[i]; cout<<endl;
}
int main(){
    int cas=1,t;

    fn(9,10);
    fn(2,5);

    return 0;
}