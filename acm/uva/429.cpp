
#include<stdio.h>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<string.h>

using namespace std;

vector<int>v[202];
int level[202];

int bfs(int source,int des)
{
    int top,k;
    queue<int>q;
    level[source]=0;
    q.push(source);
    while(!q.empty())
    {
        if(level[des]!=-1) return level[des];
        top=q.front();
        q.pop();
        for(int i=0;i<v[top].size();i++)
        {
            k=v[top][i];
            if(level[k]==-1)
            {
                level[k]=level[top]+1;
                q.push(k);
            }

        }
    }
    return -1;
}

int isit(char ara1[],char ara2[])
{
    int i,j,flag=0;
    for(i=0;ara1[i];i++)
    {
        if(ara1[i]==ara2[i]) continue;
        else if(flag) return 0;
        else flag++;
    }
    if(ara2[i]==0) return 1;
    else return 0;
}

int main()
{

    char dic[202][12],one[12],two[12];
    map<string,int>m;
    int t,i,j,k,n,f=0;
    scanf("%d",&t);
    gets(one);
    gets(one);
    while(t--){
    i=0;
    int node=0;
    while(gets(dic[i]) && dic[i][0]!='*')
    {
        m[ dic[i] ]=node++;
        i++;
    }
    n=i;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(isit(dic[i],dic[j]))
            {
                v[m[dic[i]]].push_back(m[dic[j]]);
                v[m[dic[j]]].push_back(m[dic[i]]);
            }
        }
    }
    char hmm[30];
    if(f) printf("\n");
    f=1;

    while(gets(hmm) && hmm[0])
    {
        sscanf(hmm,"%s %s",one,two);
        memset(level,-1,sizeof(level));
        printf("%s %s %d\n",one,two,bfs(m[one],m[two]));
    }
    for(i=0;i<n;i++) v[i].clear();
    m.clear();
    }
    return 0;
}
