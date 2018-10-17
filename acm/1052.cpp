#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
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
                    res[i][k]=(res[i][k]+(mat[i][j]*a.mat[j][k])%mod)%mod;
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
ll inv(ll base,ll power=mod-2,ll m=mod){
    if(power==0) return 1ll;
    if(power==1) return base;
    ll x=inv(base,power/2,mod);
    x=(x*x)%mod;
    if(power&1) x=(x*base)%mod;
    return x;
}
int main()
{
    Matrix _M(2,2);
    _M.takeIn(0,0,1);
    _M.takeIn(0,1,1);
    _M.takeIn(1,0,1);
    _M.takeIn(1,1,0);

    Matrix F(2,1);
    F.takeIn(0,0,1);
    F.takeIn(1,0,0);
//    int nth;
//    while(cin>>nth)
//    {
//        Matrix r(_M.expo(nth-1)*F);
//        cout<<r.mat[0][0]<<endl;
//    }
    int t,test=1;
    scanf("%d",&t);
    while(t--)
    {
        ll n,x,m,y,k;
        scanf("%lld%lld%lld%lld%lld",&n,&x,&m,&y,&k);
        Matrix N(_M.expo(n)*F);
        Matrix M(_M.expo(m)*F);
        ll det=(N.mat[1][0]*M.mat[0][0]-N.mat[0][0]*M.mat[1][0])%mod;
        ll X=(x*M.mat[0][0]-y*N.mat[0][0])%mod;
        ll Y=(y*N.mat[1][0]-x*M.mat[1][0])%mod;
        if(det==0 || X%det || Y%det) printf("Case %d: Impossible\n",test++);
        else
        {
            X/=det;
            Y/=det;
            if(X<0 || Y<0) {
                printf("Case %d: Impossible\n",test++);
                continue;
            }
            Matrix K(_M.expo(k)*F);
            ll ans=(X*K.mat[1][0]+Y*K.mat[0][0])%mod;
            ans=(ans+mod)%mod;
            printf("Case %d: %lld\n",test++,ans);
        }
    }
    return 0;
}

