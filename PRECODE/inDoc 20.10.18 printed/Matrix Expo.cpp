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
                    res[i][k]+=mat[i][j]*a.mat[j][k];
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
    /*
    ///MULTIPLYING TWO MATRICES
    int n,m,k;
    cin>>n>>m>>k;
    Matrix a(n,m),b(m,k);
    a.WholeInput();
    b.WholeInput();
    Matrix res=a*b;
    res.printMat();
    ///END MULTIPLY
    */

    ///FINDING THE N-TH FIBONACCCI
    Matrix M(2,2);
    M.takeIn(0,0,1);
    M.takeIn(0,1,1);
    M.takeIn(1,0,1);
    M.takeIn(1,1,0);
    Matrix F(2,1);
    F.takeIn(0,0,1);
    F.takeIn(1,0,1);
    int nth;
    while(cin>>nth)
    {
        Matrix r(M.expo(nth-1)*F);
        cout<<r.mat[0][0]<<endl;
    }
    return 0;
}

