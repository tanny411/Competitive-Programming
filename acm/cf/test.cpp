#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){

    for(int x=1;x<=1000000;x++)
    {
        int ox=x;

        int t=0;
        vector<int>v;
        while(1){
            
            if(t&1) {x++; t++; continue; }

            int last=-1,pos=0;
            int tx=x;
            while(tx){
                if(tx&1);
                else last=pos;
                pos++;
                tx/=2;
            }
            
            if(last==-1) break;

            int two=2;
            v.pb(last+1);
            while(last--) two*=2;

            x=x^two;
            t++;
        }
        if(t>40) cout<<ox<<endl;
    }
    return 0;
}