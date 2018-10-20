//#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)

#define pf1(x) printf("%d\n", x)

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define llu unsigned long long

#include<limits.h>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>

#define clr( a, b )     memset((a),b,sizeof(a))
#define max3(a,b,c)     max(a,max(b,c))
#define min3(a,b,c)     min(a,min(b,c))


#define fs first
#define sc second

///ios_base::sync_with_stdio(false)

using namespace std;
int a,b;
string aa,bb;
int dp[1007][1007];

int lcs(int i,int j)
{
    ///worst-case comlexity O(2^n)
    if(i==a || j==b) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(aa[i]==bb[j]) return dp[i][j]=1+lcs(i+1,j+1);
    else return dp[i][j]=max(lcs(i+1,j),lcs(i,j+1));
}

void print(int i,int j)
{
    if(i==a || j==b) return;
    if(aa[i]==bb[j])
    {
        cout<<aa[i]<<" "<<i+1<<" "<<j+1<<endl;
        print(i+1,j+1);
    }
    else if(dp[i+1][j]>dp[i][j+1])
    {
        print(i+1,j);
    }
    else
    {
        print(i,j+1);
    }
}
string s;
void printAll(int i,int j)
{
    if(i==a || j==b)
    {
        cout<<s<<endl;
        return;
    }
    if(aa[i]==bb[j])
    {
        s+=aa[i];
        printAll(i+1,j+1);
        s.pop_back();
    }
    else if(dp[i+1][j]==dp[i][j+1])
    {
        printAll(i+1,j);
        printAll(i,j+1);
    }
    else if(dp[i+1][j]>dp[i][j+1])
    {
        printAll(i+1,j);
    }
    else
    {
        printAll(i,j+1);
    }
}
int table[1007][1007];
int tabledp(int n,int m)
{
    ///worst-case complexity O(n*m)
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(i==0 || j==0) table[i][j]=0;
            else if(aa[i-1]==bb[j-1]) table[i][j]=1+table[i-1][j-1];
            else table[i][j]=max(table[i-1][j],table[i][j-1]);
        }
    }
    return table[n][m];
}

void printtable()
{
    int index=table[a][b];
    char lcsprn[index+1 ];
    lcsprn[index]=0;
    int i=a,j=b;
    while(i>0 && j>0)
    {
        if(aa[i-1]==bb[j-1])
        {
            lcsprn[index-1]=aa[i-1];
            index--;
            i--;
            j--;
        }
        else if(table[i-1][j]>table[i][j-1])///to print all:
        {
            ///if(table[i-1][j]==table[i][j-1])
            ///then we have to go both ways; how? I donno :3
            i--;
        }
        else
        {
            j--;
        }
    }
    puts(lcsprn);
}

int space_optimised_table_lcs()
{
    int n=a,m=b;
    int  optable[2][m+1];
    int in;
    memset(optable,0,sizeof optable);
    for(int i=0; i<=n; i++)
    {
        in=i&1;///odd hoile 1
        for(int j=0; j<=m; j++)
        {
            if(i==0 || j==0) optable[in][j]=0;
            else if(aa[i-1]==bb[j-1])
            {
                optable[in][j]=1+optable[1-in][j-1];
            }
            else
            {
                optable[in][j]=max(optable[1-in][j],optable[in][j-1]);

            }
        }
    }
    return optable[in][m];
}

int main()
{
    int n;
    int cas=1;
    cin>>n;
    while(n--)
    {
        cin>>a>>aa>>b>>bb;///aa is of length a
        ///recursion
        memset(dp,-1,sizeof(dp));
        cout<<"LCS = "<<lcs(0,0)<<endl;
        //print(0,0);
        //printAll(0,0);
        ///table dp
        /*Note that table[i][j] contains length of LCS of
        aa[0..i-1] and bb[0..j-1] */
        cout<<"LCS = "<<tabledp(a,b)<<endl;
        printtable();
        cout<<"space optimised = "<<space_optimised_table_lcs()<<endl;
    }
    return 0;
}

