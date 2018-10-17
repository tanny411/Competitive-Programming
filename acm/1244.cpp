#include<bits/stdc++.h>
#define pb push_back
#define md 10007
//http://lbv-pc.blogspot.com/2012/09/tiles.html
using namespace std;
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
                    res[i][k]=(res[i][k]+mat[i][j]*a.mat[j][k])%md;
                }
            }
        }
        return Matrix(res);
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

int main()
{
    Matrix M(4,4);
    M.mat[0][0]=M.mat[0][1]=M.mat[0][2]=M.mat[0][3]=1;
    M.mat[1][0]=M.mat[2][1]=M.mat[2][3]=M.mat[3][1]=M.mat[3][2]=1;

    Matrix F(4,1);
    F.mat[0][0]=1;
    F.mat[1][0]=1;

    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<"Case "<<test++<<": "<<(M.expo(n-1)*F).mat[0][0]<<endl;
    }
    return 0;
}

