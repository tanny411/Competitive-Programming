#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

string deo(int x,int y){
    string mat[x+2];
    string disi[5]={
        "aeiou","uaeio","ouaei","iouae","eioua"
    };
    for(int i=0;i<x;i++){
        mat[i]+=disi[i%5];
    }
    for(int j=5;j<y;j++){
        for(int i=0;i<5;i++){
            mat[i]+=disi[0][i];
        }
        for(int i=5;i<x;i++){
            mat[i]+='o';
        }
    }
    string ans;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            ans+=mat[i][j];
            //cout<<mat[i][j];
        }
       // cout<<endl;
    }
    return ans;
}

int main(){
    int k;
    cin>>k;
    if(k<25) {
        cout<<"-1"<<endl;
        return 0;
    }
    for(int i=5;i<=k;i++){
        if(k%i==0 && k/i>=5){
            cout<<deo(i,k/i)<<endl;
            return 0;
        }
    }
    cout<<"-1"<<endl;
    return 0;
}