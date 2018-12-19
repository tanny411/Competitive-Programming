#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v[30];
    char flag[30];
    queue<int>q;

    int test,n,Count,f=0,top,i,j;
    char a,b;
    scanf("%d",&test);
    getchar();
    getchar();
    char cop[3];
    while(test--)
    {

        a=getchar();
        getchar();

        n=a-64;

        memset(flag,0,sizeof(flag));
        for(i=0;i<n;i++) v[i].clear();

        while(gets(cop) && cop[0])
        {
            a=cop[0];
            b=cop[1];
            v[a-65].push_back(b-65);
            v[b-65].push_back(a-65);
        }
        Count=0;
        for(i=0;i<n;i++)
        {
            if(!flag[i])
            {
                Count++;
                q.push(i);
                while(!q.empty())
                {
                    top=q.front();
                    q.pop();
                    flag[top]=1;
                    for(j=0;j<v[top].size();j++)
                    {
                        int x=v[top][j];
                        if(!flag[x])
                        {
                            flag[x]=1;
                            q.push(x);
                        }
                    }
                }
            }
        }
        if(f) printf("\n");
        f=1;
        printf("%d\n",Count);

    }
    return 0;
}
