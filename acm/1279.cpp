#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll mat[102][102];
const ll mod=1000000007;
void swap(int row1, int row2,int col)
{
    for (int i = 0; i < col; i++)
    {
        ll temp = mat[row1][i];
        mat[row1][i] = mat[row2][i];
        mat[row2][i] = temp;
    }
}
ll bg(ll b,ll p,ll mod){
    if(p==0) return 1ll;
    ll x=bg(b,p/2,mod);
    x=(x*x)%mod;
    if(p&1) x=(x*b)%mod;
    return x;
}
int rankOfMatrix(ll k,int R,int C)
{
    int rank = C;
    for (int row = 0; row < rank; row++)
    {
        if(mat[row][row])
        {
            ll s=bg(mat[row][row],k-2,k);
           for (int col = 0; col < R; col++)
           {
               if (col != row)
               {
                 ll mult = (mat[col][row]*s)%k;
                 for (int i = 0; i < rank; i++)
                   mat[col][i] = ((mat[col][i] - mult * mat[row][i])%k+k)%k;
              }
           }
        }
        else
        {
            bool reduce = true;
            for (int i = row + 1; i < R;  i++)
            {
                if (mat[i][row])
                {
                    swap(row, i, rank);
                    reduce = false;
                    break ;
                }
            }
            if (reduce)
            {
                rank--;
                for (int i = 0; i < R; i ++)
                    mat[i][row] = mat[i][rank];
            }
            row--;
        }
    }
    return rank;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        memset(mat,0,sizeof mat);
        vector<int>v[n+2];
        while(m--)
        {
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            v[x].pb(y);
            v[y].pb(x);
        }
        for(int i=0;i<n;i++)
        {
            mat[i][i]=k-1;
            for(int j=0;j<v[i].size();j++)
            {
                mat[i][v[i][j]]=1;
            }
        }
        ///Solution is k^(n-rank)
        cout<<"Case "<<test++<<": "<<bg(k,n-rankOfMatrix(k,n,n),mod)<<endl;
    }
    return 0;
}

