/*
https://turing13.wordpress.com/2016/09/25/light-oj-1070-algebraic-problem/
Solution Idea:

Meaning of the questions:
You p = a + b, q = ab

Calculating (a ^ n + b ^) mod2 ^ 64

practice:

mod 2 ^ 64 so open unsigned long long, llu on the line, reaches the upper limit will be automatically modulo.

Then the formula is. I was pushing the law found in the formula.

a ^ 2 + b ^ 2 = (a + b) * (a + b) -2 * a * b

a ^ 3 + b ^ 3 = (a ^ 2 + b ^ 2) * (a + b) -a * b (a + b)

a ^ 4 + b ^ 4 = (a ^ 3 + b ^ 3) * (a + b) -a * b (a ^ 2 + b ^ 2)

now --

1.a^n + b^n = (a^(n-1)+b^(n-1))*(a+b) - a*b*(a^(n-2)+b^(n-2))

2.  Xn = a^n + b^n

3 . Xn = pXn-1 + qXn-2

    (p q)      (Xn-1)         (pXn-1 + qXn-2)         (Xn  )
4.         x               =                      =
    (1 0)      (Xn-2)         ( Xn-1 +  0  )          (Xn-1)

5 . from this

    (p q)^(n-1)     (X1)     (Xn   )
                x          =
    (1 0)           (X0)     (Xn-1)

*/
#include<bits/stdc++.h>
#define pb push_back
#define ll unsigned long long
using namespace std;
int mod;
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
    Matrix M(2,2);
    M.takeIn(1,0,1);
    M.takeIn(1,1,0);
    Matrix F(2,1);
    int t,test=1;
    scanf("%d",&t);
    while(t--)
    {
        ll p,q,n;
        scanf("%llu%llu%llu",&p,&q,&n);
        M.takeIn(0,0,p);
        M.takeIn(0,1,-q);
        F.takeIn(0,0,p);
        F.takeIn(1,0,2);
        if(n==0){
            printf("Case %d: 2\n",test++);
            continue;
        }
        Matrix r(M.expo(n-1)*F);
        printf("Case %d: %llu\n",test++,r.mat[0][0]);
    }
    return 0;
}


