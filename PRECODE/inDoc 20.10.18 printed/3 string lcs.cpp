#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define LL long long
#define LLU unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;

///3 string lcs
///can be extended to n strings by n-dimensional array
int do_lcs(string a,string b,string c)
{
    int la=a.length();
    int lb=b.length();
    int lc=c.length();
    int ara[la+1][lb+1][lb+1];
    for(int i=0;i<=la;i++)
    {
        for(int j=0;j<=lb;j++)
        {
            for(int k=0;k<=lc;k++)
            {
                if(i==0 || j==0 || k==0) ara[i][j][k]=0;
                else if(a[i-1]==b[j-1]&& b[j-1]==c[k-1]) ara[i][j][k]=1+ara[i-1][j-1][k-1];
                else ara[i][j][k]=max(ara[i-1][j][k],max(ara[i][j-1][k],ara[i][j][k-1]));
            }
        }
    }
    return ara[la][lb][lc];
}

int main()
{
    string a,b,c;
    cin>>a>>b>>c;
    cout<<do_lcs(a,b,c)<<endl;
    return 0;
}

