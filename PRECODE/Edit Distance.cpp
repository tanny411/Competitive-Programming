#include<bits/stdc++.h>
using namespace std;
string aa,bb;
int dp[1000][1000];

int rec_edit(int i,int j)
{
    ///(i,j) means (0 to i),(0 to j) will be calculated and stored in (i,j)
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==0) return j;
    if(j==0) return i;
    if(aa[i-1]==bb[j-1]) return dp[i][j]=rec_edit(i-1,j-1);
    return dp[i][j]=1+min(rec_edit(i-1,j),min(rec_edit(i,j-1),rec_edit(i-1,j-1)));
}
void print_edit(int n,int m, int table[100][100])
{
    string a=aa;///for printing the string while editing
    ///all opertaions done on first string
    int i=n;
    int j=m;
    while(i>-1 && j>-1)
    {
        if(i==0 && j==0) break;
        else if(i==0)
        {
            cout<<j<<"I";///j characters inserted
            a.insert(0,bb.substr(0,j));
            i=j=-2;
        }
        else if(j==0)
        {
            cout<<i<<"D";///i characters deleted
            a.erase(0,i);
            i=j=-2;
        }
        else if(aa[i-1]==bb[j-1])
        {
            cout<<"M";///match found
            i--;
            j--;
        }
        else
        {
            if(table[i][j]==1+table[i-1][j-1])
            {
                cout<<"S";///character aa[i] substituted by charater bb[j]
                a[i-1]=bb[j-1];
                i--;
                j--;
            }
            else if(table[i][j]==1+table[i-1][j])
            {
                cout<<"D";/// character aa[i] deleted
                a.erase(a.begin()+i-1);
                i--;
            }
            else if(table[i][j]==1+table[i][j-1])
            {
                cout<<"I";///character bb[j] inserted at i
                a.insert(a.begin()+i,bb[j-1]);
                j--;
            }
        }
        cout<<"  string: "<<a<<endl;
        if(i==-2 || j==-2) break;
    }
}

int table_edit(int n,int m)
{
    //int table[n+2][m+2];
    int table[100][100];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(i==0) table[i][j]=j;
            else if(j==0) table[i][j]=i;
            else if(aa[i-1]==bb[j-1]) table[i][j]=table[i-1][j-1];
            else table[i][j]=1+min( table[i-1][j-1], min( table[i-1][j],table[i][j-1] ) );
        }
    }
    /*for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<table[i][j];
        }
        cout<<endl;
    }*/
    print_edit(n,m,table);
    return table[n][m];
}

int space_optimised(int n,int m)
{
    int table[2][m+1];
    int bi;
    for(int i=0; i<=n; i++)
    {
        bi=i&1;
        for(int j=0; j<=m; j++)
        {
            if(i==0) table[bi][j]=j;
            else if(j==0) table[bi][j]=i;
            else if(aa[i-1]==bb[j-1]) table[bi][j]=table[1-bi][j-1];
            else table[bi][j]=1+min(table[1-bi][j],min(table[bi][j-1],table[1-bi][j-1]));
        }
    }
    return table[bi][m];
}


int main()
{
    cin>>aa>>bb;
    memset(dp,-1,sizeof dp);
    cout<<rec_edit(aa.length(),bb.length())<<endl;
    cout<<endl<<table_edit(aa.length(),bb.length())<<endl;
    cout<<space_optimised(aa.length(),bb.length())<<endl;
    return 0;
}
