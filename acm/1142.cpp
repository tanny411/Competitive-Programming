#include<bits/stdc++.h>
#define pb push_back

using namespace std;
///Did not Deal with doing mod; for that put mod in the multiply function;all replace all int with long long
struct Matrix
{
    vector<vector<int> >mat;
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
    Matrix(vector<vector<int> >val): mat(val),row(val.size()),col(val[0].size()) {}

    void takeIn(int i,int j,int val)
    {
        mat[i][j]=val;
    }

    Matrix operator*(const Matrix &a) const
    {
        int m=a.col;
        vector<vector<int> >res(row,vector<int>(m));
        for(int i=0; i<row; i++)
        {
            for(int k=0; k<m; k++)
            {
                for(int j=0; j<col; j++)
                {
                    res[i][k]=(res[i][k]+mat[i][j]*a.mat[j][k])%10;;
                }
            }
        }
        return Matrix(res);
    }
    Matrix operator+(const Matrix &a) const
    {
        Matrix ret(row,col);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                ret.mat[i][j]=(mat[i][j]+a.mat[i][j])%10;
            }
        }
        return ret;
    }
    Matrix identity(int n)
    {
        Matrix a(n,n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j) a.mat[i][j]=1;
            }
        }
        return a;
    }

    Matrix expo(int power)
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
Matrix bigsum(Matrix a,int n)
{
    if(n==1) return a.identity(a.row);
    if(n&1) return a.identity(a.row) + a*bigsum(a,n-1);
    Matrix ret=bigsum(a*a,n/2);
    return ret+a*ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        Matrix a(n,n);
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a.mat[i][j];
        a=a*bigsum(a,k);///power 0...k-1
        cout<<"Case "<<test++<<":\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<<a.mat[i][j];
            cout<<endl;
        }
    }
    return 0;
}


