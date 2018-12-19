#include<bits/stdc++.h>
#define pf printf
#define sf scanf
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
using namespace std;

char s[100];
int len,good,bad;
int dp[51][6][6];

int isvowel(char x)
{
    return x=='A' || x=='E' || x=='I' || x=='O' || x=='U';

}

int rec(int i,int c,int v)
{

    if(c>=5 || v>=3) {bad=1; return 1;}
    if(i==len) {good=1; return 1;}
    if(good && bad) return 1;
    int &ret=dp[i][c][v];
    if(ret!=-1) return ret;
    if(s[i]==1) return ret=rec(i+1,0,v+1);
    else if(s[i]==0) return ret=rec(i+1,c+1,0);
    else
    {
        ret=rec(i+1,c+1,0);
        if(good && bad) return ret=1;
        ret=rec(i+1,0,v+1);
    }
    if(good && bad) return ret=1;
}

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(s);
        int d;
        len=strlen(s);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<len;i++)
        {
            if(s[i]=='?') s[i]=2;
            else s[i]=isvowel(s[i]);
        }
        good=0;
        bad=0;
        rec(0,0,0);
        /*
        for(int i=0;i<strlen(s);i++)
        {
            for(int j=0;j<6;j++)
            {
                for(int k=0;k<4;k++)
                {
                    cout<<dp[i][j][k];
                }
            }
        }
        */
        printf("Case %d: ",cas++);
        if(good && bad) printf("MIXED\n");
        else if(good) printf("GOOD\n");
        else printf("BAD\n");

    }
    return 0;
}
