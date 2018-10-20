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

int n;
int solve(int row,int minDiag, int majDiag, int col){
    if(row==n) return 1;
    int res=0;
    int conflict=minDiag|majDiag|col;
    for(int queenPos=1;queenPos < 1<<n ;queenPos<<=1){
        if(!(conflict & queenPos))
        {
            int nextMinDiag=(minDiag|queenPos)>>1;
            int nextMajDiag=(majDiag|queenPos)<<1;
            int nextCol=col|queenPos;
            res+=solve(row+1,nextMinDiag,nextMajDiag,nextCol);
        }
    }
    return res;
}

int main()
{
    cin>>n;
    cout<<solve(0,0,0,0)<<endl;
    return 0;
}
