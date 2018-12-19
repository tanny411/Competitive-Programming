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
using namespace std;

bool prime[101];
int ara[101][101];



void sieve()
{
    int i,j;
    for(i=2;i<101;i+=2)
    {
        int a=i;
        while(a%2==0)
        {
            ara[i][2]++;
            a/=2;
        }
    }
    for(i=3;i<101;i+=2)
    {
        if(!prime[i])
        {
            for(j=i;j<101;j+=i)
            {
                int a=j,c=0;
                while(a%i==0)
                {
                    ara[j][i]++;
                    a/=i;
                }
                prime[j]=1;
            }
        }
    }
}

int main()
{
    sieve();

    for(int i=3;i<101;i++)
    {
        for(int j=0;j<101;j++)
        {
            ara[i][j]+=ara[i-1][j];
        }
    }

    int t,T,a;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&a);
        printf("Case %d: %d = ",t,a);
        int i;
        for(i=0;i<101;i++)
        {
            if(ara[a][i])
            {
                printf("%d (%d)",i,ara[a][i]);
                i++;
                break;
            }
        }
        for(;i<101;i++)
        {
            if(ara[a][i])
            {
                printf(" * %d (%d)",i,ara[a][i]);
            }
        }
        printf("\n");
    }
    return 0;
}
