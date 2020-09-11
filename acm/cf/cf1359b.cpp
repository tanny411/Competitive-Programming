#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

char mat[103][1003];

int main(){
    int cas=1,t;
    cin>>t;
    while(t--){
        int n,m,x,y, pair=0, white=0;
        cin>>n>>m>>x>>y;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
                if(mat[i][j]=='.') {
                    white++;
                    if(j && mat[i][j-1]=='.'){
                        pair++;
                        mat[i][j]=mat[i][j-1]='p';
                    }
                }

            }
        }
        if((x+x)<=y) cout<<white*x<<endl;
        else {
            white -= 2*pair;
            cout<<white*x + pair*y<<endl;
        }
    }

    return 0;
}