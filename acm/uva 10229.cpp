#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
///Did not Deal with doing mod; for that put mod in the multiply function;all replace all int with long long
ll md;
ll two[30];
struct Matrix
{
    vector<vector<ll> >mat;
    int row,col;

    Matrix() {}
    Matrix (const Matrix &a)
    {
        mat=a.mat;
        row=a.row;
        col=a.col;
    }
    Matrix(int row,int col):row(row),col(col)
    {
        mat.resize(row);
        for(int i=0; i<row; i++)
        {
            mat[i].resize(col);
        }
    }
    Matrix(vector<vector<ll> >val): mat(val),row(val.size()),col(val[0].size()) {}

    void takeIn(int i,int j,ll val)
    {
        mat[i][j]=val;
    }

    Matrix operator*(const Matrix &a) const
    {
        int m=a.col;
        vector<vector<ll> >res(row,vector<ll>(m));
        for(int i=0; i<row; i++)
        {
            for(int k=0; k<m; k++)
            {
                for(int j=0; j<col; j++)
                {
                    res[i][k]=(res[i][k]+(mat[i][j]*a.mat[j][k])%md)%md;
                }
            }
        }
        return Matrix(res);
    }

    Matrix identity(int n)
    {
        Matrix a;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j) a.mat[i][j]=1ll;
            }
        }
        return a;
    }

    Matrix expo(ll power)
    {
        if(power==1) return mat;
        if(power==0) return identity(row);
        Matrix x=expo(power/2);
        x=x*x;
        if(power&1) x=x*mat;
        return x;
    }
    void printMat()
    {
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void WholeInput()
    {
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                cin>>mat[i][j];
            }
        }
    }
};

int main()
{
    Matrix F(2,1);
    F.takeIn(0,0,1);F.takeIn(1,0,0);
    Matrix M(2,2);
    M.takeIn(0,0,1);M.takeIn(0,1,1);M.takeIn(1,0,1);M.takeIn(1,1,0);
    two[0]=1;
    for(int i=1;i<24;i++) two[i]=two[i-1]*2;
    ll n;
    while(cin>>n>>md)
    {
        md=two[md];
        if(n==0) cout<<0<<endl;
        else if(n==1) cout<<1%md<<endl;
        else cout<<(M.expo(n-1)*F).mat[0][0]<<endl;
    }
    return 0;
}

