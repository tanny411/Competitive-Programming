#include<bits/stdc++.h>
#define pb push_back
#define ui unsigned int
#define ll long long
using namespace std;
struct Matrix
{
    vector<vector<ui> >mat;
    ui row,col;

    Matrix() {}
    Matrix (const Matrix &a)
    {
        mat=a.mat;
        row=a.row;
        col=a.col;
    }
    Matrix(ui row,ui col):row(row),col(col)
    {
        mat.resize(row);
        for(ui i=0; i<row; i++)
        {
            mat[i].resize(col);
        }
    }
    Matrix(vector<vector<ui> >val): mat(val),row(val.size()),col(val[0].size()) {}

    void takeIn(ui i,ui j,ui val)
    {
        mat[i][j]=val;
    }

    Matrix operator*(const Matrix &a) const
    {
        ui m=a.col;
        vector<vector<ui> >res(row,vector<ui>(m));
        for(ui i=0; i<row; i++)
        {
            for(ui k=0; k<m; k++)
            {
                for(ui j=0; j<col; j++)
                {
                    res[i][k]+=mat[i][j]*a.mat[j][k];
                }
            }
        }
        return Matrix(res);
    }

    Matrix identity(ui n)
    {
        Matrix a(n,n);
        for(ui i=0; i<n; i++)
        {
            for(ui j=0; j<n; j++)
            {
                if(i==j) a.mat[i][j]=1;
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
        for(ui i=0; i<row; i++)
        {
            for(ui j=0; j<col; j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void WholeInput()
    {
        for(ui i=0; i<row; i++)
        {
            for(ui j=0; j<col; j++)
            {
                cin>>mat[i][j];
            }
        }
    }
};
ui ncr[55][55];
int main()
{
    ios_base::sync_with_stdio(false);
    for(int i=0;i<51;i++) {ncr[i][0]=1;ncr[i][i]=1;}
    for(int i=1;i<51;i++){
        for(int j=1;j<i;j++){
            ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
        }
    }

    int t,test=1;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;

        Matrix M(k+2,k+2);
        Matrix F(k+2,1);

        M.takeIn(0,0,1);
        for(int i=1;i<=k+1;i++)
        {
            M.takeIn(0,i,ncr[k][i-1]);
        }
        for(int i=1;i<=k+1;i++)
        {
            for(int j=i,cnt=0;j<=k+1;j++,cnt++)
            {
                M.takeIn(i,j,ncr[k-(i-1)][cnt]);
            }
        }
        for(int i=0;i<=k+1;i++) F.takeIn(i,0,1);

        cout<<"Case "<<test++<<": "<<(M.expo(n-1)*F).mat[0][0]<<endl;
    }
    return 0;
}


