#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;

    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int ln = str.length();
        vector<int>d(ln),a(ln),s(ln),w(ln);
        for(int i=ln-2;i>=0;i--){
            a[i]=a[i+1];
            s[i]=s[i+1];
            d[i]=d[i+1];
            w[i]=w[i+1];
            if(str[i+1]=='A') a[i]++;
            else if(str[i+1]=='S') s[i]++;
            else if(str[i+1]=='D') d[i]++;
            else w[i]++;
        }
        //x,y in terms of row and column
        //not the axes
        int xu=0,xd=0,yl=0,yr=0;//edges
        int ox=0,oy=0; //origin
        for(int i=0;i<ln;i++){
            if(str[i]=='A') oy--;
            else if(str[i]=='D') oy++;
            else if(str[i]=='S') ox--;
            else ox++;
            xu=max(xu,ox);
            xd=min(xd,ox);
            yr=max(yr,oy);
            yl=max(yl,oy);
        }

        ox=0;oy=0; //restart travelling
        int area=(yr-yl+1)*(xu-xd+1);
        
        for(int i=0;i<ln;i++){
            
        }
    }

    return 0;
}