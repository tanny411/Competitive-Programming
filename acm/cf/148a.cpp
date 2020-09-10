#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int lcm(int a, int b){
    int g = __gcd(a, b);
    g = a/g;
    return b*g;
}

int main(){
    vector<int>ones = vector<int>(4);
    int tot;
    for(int i=0;i<4;i++) cin>>ones[i];
    cin>>tot;
    int out = 0;
    for (int i=0;i<4;i++){
        out += tot/ones[i];
        for(int j=i+1;j<4;j++){
            int lc = lcm(ones[i], ones[j]);
            out -= tot/lc;
            for (int k=j+1;k<4;k++){
                int lc3 = lcm(lc, ones[k]);
                out += tot/lc3;
            }
        }
    }
    out -= tot/lcm(lcm(ones[0],ones[1]), lcm(ones[2],ones[3]));
    
    cout<<out<<endl;
    return 0;
}