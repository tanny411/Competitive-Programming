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

vector<int>facts[10000];
int flag[10002];

void sieve()
{
    vector<int>prime;
    prime.pb(2);
    for(int i=4;i<=10000;i+=2) facts[i].pb(2);
    for(int i=3;i<=10000;i+=2)
    {
        if(!flag[i])
        {
            prime.pb(i);
            for(int j=i+i;j<=10000;j+=i)
            {
                flag[j]=1;
                facts[j].pb(i);
            }
        }
    }
    /*
    for(int i=0;i<100;i++)
    {
        cout<<i<<":  ";
        for(int j=0;j<facts[i].size();j++)
        {
            cout<<" "<<facts[i][j];
        }
        cout<<endl;
    }
    */
}

int main()
{
    sieve();
    int test,cas=1;
    cin>>test;
    while(test--)
    {
        int s,d;
        cin>>s>>d;
        queue<int>q;
        vector<int>level(d+2,-1);
        q.push(s);
        level[s]=0;
        while(!q.empty() && level[d]==-1)
        {
            int x=q.front();
            q.pop();
            for(int i=0;i<facts[x].size();i++)
            {
                int y=x+facts[x][i];
                if(y<=d && level[y]==-1)
                {
                    level[y]=level[x]+1;
                    q.push(y);
                }
            }
        }
        printf("Case %d: %d\n",cas++,level[d]);
    }
    return 0;
}
