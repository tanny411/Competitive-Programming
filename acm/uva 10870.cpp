#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define LLU unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

ll md;
using namespace std;
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
                    res[i][k]=((res[i][k]+(mat[i][j]*a.mat[j][k])%md)%md+md)%md;
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
    ll d,n;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>d>>md>>n;
        Matrix M(d+1,d+1),F(d+1,1);
        for(int i=0; i<d; i++)
        {
            ll x;
            cin>>x;
            if(x<0) x=md-(-x)%md;
            x%=md;
            M.takeIn(0,i,x);
        }
        M.takeIn(0,d,1);
        int C;
        cin>>C;
        for(int i=1; i<d; i++)
        {
            M.takeIn(i,i-1,1);
        }
        M.takeIn(d,d,1);

        vector<int>D(d+2);
        for(int i=0; i<d; i++)
        {
            ll x;
            cin>>x;
            if(x<0) x=md-(-1*x)%md;
            x%=md;
            D[i]=x;
            F.takeIn(d-i-1,0,x);
        }
        F.takeIn(d,0,C);
        if(n<d) cout<<D[n]%md<<endl;
        else
        {
            cout<<(M.expo(n-d+1)*F).mat[0][0]<<endl;
        }
        if(t) cout<<endl;
    }
    return 0;
}

