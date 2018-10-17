#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int md;
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
    Matrix M(6,6);

    M.takeIn(1,0,1);
    M.takeIn(2,1,1);
    M.takeIn(5,4,1);
    M.takeIn(4,3,1);

    Matrix F(6,1);

    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n,a1,b1,c1,q;
        int a2,b2,c2;
        int g0,g1,g2;
        int f0,f1,f2;
        cin>>a1>>b1>>c1>>a2>>b2>>c2>>f0>>f1>>f2>>g0>>g1>>g2>>md>>q;

        a1%=md;b1%=md;c1%=md;a2%=md;b2%=md;c2%=md;f0%=md;f1%=md;f2%=md;g0%=md;g1%=md;g2%=md;//was getting wa without this >.<

        F.takeIn(0,0,f2);
        F.takeIn(1,0,f1);
        F.takeIn(2,0,f0);
        F.takeIn(3,0,g2);
        F.takeIn(4,0,g1);
        F.takeIn(5,0,g0);

        M.takeIn(0,0,a1);
        M.takeIn(0,1,b1);
        M.takeIn(0,5,c1);
        M.takeIn(3,2,c2);
        M.takeIn(3,3,a2);
        M.takeIn(3,4,b2);

        cout<<"Case "<<test++<<":\n";
        while(q--){
            cin>>n;
            if(n<3){
                if(n==0) cout<<f0<<" "<<g0<<endl;
                else if(n==1) cout<<f1<<" "<<g1<<endl;
                if(n==2) cout<<f2<<" "<<g2<<endl;
            }
            else{
                Matrix r(M.expo(n-2)*F);
                cout<<r.mat[0][0]<<" "<<r.mat[3][0]<<endl;
            }
        }
    }
    return 0;
}


