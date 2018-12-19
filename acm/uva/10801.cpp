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
#define HI(x) printf("        HI %d\n",x);
using namespace std;


vector<pii>v[503];
/// 100*5 + 3 ///for the i-th lift add 100*i to the node number
int level[503],n,k;
vector<int>a[5];

class comp
{
public:
    bool operator()(pii a,pii b)
    {
        return a.second>b.second;
    }
};

void Dijkstra(int s)
{
    priority_queue<pii,vector<pii>,comp>q;
    level[s]=0;
    q.push(pii(s,0));
    while(!q.empty())
    {
        pii x=q.top();
        q.pop();
        for(int i=0;i<v[x.first].size();i++)
        {
            if( level[ v[x.first][i].first ] > level[x.first]+v[x.first][i].second )
            {
                level[ v[x.first][i].first ] = level[x.first]+v[x.first][i].second;
                q.push(pii(v[x.first][i].first,level[v[x.first][i].first]));
            }
        }
    }
}

void bsearch(vector<int>A,vector<int>B,int inx,int iny)
{
    int len=B.size();
    for(int i=0;i<A.size();i++)
    {
        int x=A[i];
        int start=0,stop=len-1,mid;
        while(start<=stop)
        {
            mid=(start+stop)/2;
            if(B[mid]==x)
            {
                v[inx*100 + x].push_back(pii(iny*100+x,60));
                v[iny*100+x].push_back(pii(inx*100 + x,60));
                break;
            }
            else if(B[mid]>x) stop=mid-1;
            else start=mid+1;
        }
    }
}

int main()
{
    freopen("out.txt","w",stdout);
    int T[10],x,y;
    char ara[100000];
    while(scanf("%d %d",&n,&k)==2)
    {
        for(int i=0;i<502;i++) v[i].clear();

        for(int i=0;i<n;i++)
        {
            scanf("%d",&T[i]);

        }
        getchar();
        int h;
        stringstream ss;
        {
            a[0].clear();
            gets(ara);
            ss.clear();
            ss<<ara;
            ss>>y;
            a[0].push_back(y);
            while(ss>>x)
            {
                a[0].push_back(x);
                h=( x-y )*T[0];
                v[x].push_back( pii(y,h) );
                v[y].push_back( pii(x,h) );
                y=x;
            }
        }
        for(int i=1;i<n;i++)
        {
            gets(ara);
            ss.clear();
            a[i].clear();
            ss<<ara;
            ss>>y;
            a[i].push_back(y);
            y+=i*100;
            while(ss>>x)
            {
                a[i].push_back(x);
                x+=i*100;
                h=( x-y )*T[i];
                v[x].push_back( pii(y,h) );
                v[y].push_back( pii(x,h) );
                y=x;
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                {
                    bsearch(a[i],a[j],i,j);
                }
        }

        for(int i=0;i<=n*100;i++)
        {
            level[i]=1<<30;
        }

        for(int i=0;i<=n*100;i+=100)  Dijkstra(i);

        int mn=1<<30;
        for(int i=k;i<=n*100;i+=100)
        {
            if(level[i]<mn) mn=level[i];
        }
        if(mn==1<<30)
        {
            printf("IMPOSSIBLE\n");
        }
        else printf("%d\n",mn);

        /*
        for(int i=0; i<n*100; i++)
        {
            if(!v[i].empty())printf("%d - ",i);
            for(int j=0;j<v[i].size();j++)
            {
                printf("(%d , %d)",v[i][j].first,v[i][j].second);
            }
            if(!v[i].empty())printf("\n");
        }
        */

    }
    return 0;
}
