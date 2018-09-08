#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define LL long long
#define LLU unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;
vector<pii>pos;
int n;
vector< vector<int> >ans;
vector<int>v(8);
int solve(int curRow,int minDiag, int majDiag, int col){
    if(curRow==n) {
        ans.pb(v);
        return 1;
    }
    int res=0;
    int conflict=minDiag|majDiag|col;
    for(int queenPos=1,c=0;queenPos < 1<<n ;queenPos<<=1,c++){
        if(!(conflict & queenPos))
        {
            int nextMinDiag=(minDiag|queenPos)>>1;
            int nextMajDiag=(majDiag|queenPos)<<1;
            int nextCol=col|queenPos;

            v[curRow]=c;
            res+=solve(curRow+1,nextMinDiag,nextMajDiag,nextCol);
        }
    }
    return res;
}

int dp[8][1<<8];
int cost(int sol,int row,int ith){
    int r1=pos[ith].fs;
    int c1=pos[ith].sc;
    int r2=row;
    int c2=ans[sol][row];
    if(r1==r2 && c1==c2) return 0;
    if(abs(r1-r2)==abs(c1-c2)) return 1;
    if(r1==r2 || c1==c2) return 1;
    return 2;
}
int rec(int sol,int row, int mask){
    ///mask says kon kon 'q' niye nisi
    if(row==n) return 0;
    if(dp[row][mask]!=-1) return dp[row][mask];
    int ret=1<<30;
    for(int i=0;i<8;i++){
        if(!(mask&(1<<i))){
            ret=min(ret,cost(sol,row,i)+rec(sol,row+1,mask|(1<<i)));
        }
    }
    return dp[row][mask]=ret;
}

int main()
{
    n=8;
    solve(0,0,0,0);
    //cout<<ans.size()<<endl;
    int t,test=1;
    cin>>t;
    while(t--)
    {
        pos.clear();
        for(int i=0;i<n;i++)
        {
            string str;
            cin>>str;
            for(int j=0;j<n;j++)
            {
                if(str[j]=='q') pos.pb(pii(i,j));
            }

        }
        int huu=1<<30;
        for(int i=0;i<ans.size();i++)
        {
            memset(dp,-1,sizeof dp);
            huu=min(huu,rec(i,0,0));
        }
        cout<<"Case "<<test++<<": "<<huu<<endl;
    }
    return 0;
}
