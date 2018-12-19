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
#define pci pair<char,int>
using namespace std;

bool comp(pci a,pci b)
{
    if(a.second!=b.second)
    return a.second>b.second;
    return a.first<b.first;
}

int m,n;
char ara[51][51];
int dirx[]={-1,1,0,0},diry[]={0,0,-1,1};

int floodfill(int x, int y)
{
    int Count=1;
    char a=ara[x][y];
    ara[x][y]='.';
    queue<pii>q;
    q.push(pii(x,y));
    while(!q.empty())
    {
        pii top=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            x=top.first+dirx[i];
            y=top.second+diry[i];
            if(x>=0 && y>=0 && x<m && y<n && ara[x][y]==a)
            {
                Count++;
                ara[x][y]='.';
                q.push(pii(x,y));
            }
        }
    }
    return Count;
}

int main()
{
    int t=1;
    freopen("out.txt","w",stdout);
    int x;
    while(scanf("%d %d",&m,&n)==2)
    {
        if(m==0 && n==0) return 0 ;
        vector<pci>v;
        getchar();
        for(int i=0;i<m;i++) gets(ara[i]);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ara[i][j]!='.')
                {
                    char a=ara[i][j];
                    x=floodfill(i,j);
                    v.pb(pci(a,x));
                }
            }
        }
        sort(v.begin(),v.end(),comp);
        printf("Problem %d:\n",t++);
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }
    }
    return 0;
}
