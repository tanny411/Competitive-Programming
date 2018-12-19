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

vector<int>v[10001];
bool flag[10001];

int floodfill(int a)
{
    if(flag[a]) return 0;
    int count=1;
    flag[a]=true;
    queue<int>q;
    q.push(a);
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        for(int i=0;i<v[top].size();i++)
        {
            if(flag[v[top][i]]==0)
            {
                flag[v[top][i]]=1;
                count++;
                q.push(v[top][i]);
            }
        }
    }
    return count;
}

int main()
{
    //freopen("out.txt","w",stdout);
    int t,m,n,l,i,j,k,a,b;
    scanf("%d",&t);
    while(scanf("%d %d %d",&n,&m,&l)==3)
    {
        for(i=1;i<=n;i++) v[i].clear();
        while(m--)
        {
            scanf("%d %d",&a,&b);
            v[a].pb(b);
        }
        for(i=1;i<=n;i++) flag[i]=false;
        int c=0;
        while(l--)
        {
            scanf("%d",&a);
            c+=floodfill(a);
        }
        printf("%d\n",c);
    }
    return 0;
}
