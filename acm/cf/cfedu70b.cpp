#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;

    string s;
    cin>>s;
    int ln = s.length();
    vector<int>ss(ln);
    
    //find values
    for(int i=1;i<ln;i++){
        if(s[i]>s[i-1]) ss[i]=s[i]-s[i-1];
        else ss[i]=(10+s[i]-s[i-1])%10;
    }
    
    vector< vector<int> >v(10,vector<int>(10));
    int dp[10][10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++) dp[i][j][k]=1000000;
        }
    }
    
    //preprocess 10^4
    for(int i=0;i<10;i++){
        for(int j=i;j<10;j++){
            for(int cnti=0;cnti<10;cnti++){
                for(int cntj=0;cntj<10;cntj++){
                    if(cnti==cntj && cnti==0) continue;
                    int num = (i*cnti+j*cntj)%10;
                    dp[i][j][num]=min(dp[i][j][num],cnti+cntj-1);
                    dp[j][i][num]=dp[i][j][num];
                }
            }
        }
    }

    // for(int i=0;i<10;i++){
    //     for(int j=0;j<10;j++){
    //         for(int k=0;k<10;k++){
    //             if(dp[i][j][k]>1000000){
    //                 cout<<i<<" "<<j<<" "<<k<<endl;
    //             }
    //         }
    //     }
    // }

    // for (int i=0;i<10;i++){
    //     cout<<dp[1][1][i]<<" ";
    // }
    // cout<<endl;
    // for (int i=0;i<10;i++){
    //     cout<<dp[0][1][i]<<" ";
    // }
    // cout<<endl;
    // cout<<endl;

    //sum answers
    for(int i=0;i<10;i++){
        for(int j=i;j<10;j++){
            for(int k=1;k<ln;k++){
                if(dp[i][j][ss[k]]==1000000){
                    v[i][j]=v[j][i]=-1;
                    break;
                }
                v[i][j]+=dp[i][j][ss[k]];
                if(i!=j) v[j][i]+=dp[i][j][ss[k]];
            }
        }
    }

    for (int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(j) cout<<" ";
            cout<<max(-1,v[i][j]);
        }
        cout<<endl;
    }
    return 0;
}