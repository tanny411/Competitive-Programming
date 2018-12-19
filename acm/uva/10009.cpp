#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    //freopen("out.txt","w",stdout);
    int t,f=0;
    map<char,int>m;
    scanf("%d",&t);
    while(t--)
    {
        m.clear();
        int e,qu,node=1;
        scanf("%d %d",&e,&qu);
        getchar();
        vector<int>v[e+2];
        char revmap[e+2];
        char ch1,ch2,g;
        int x=e;
        while(x--)
        {
        ch1=getchar();
        ch2='a';
        while(ch2!=' ') ch2=getchar() ;
        ch2=getchar();
        g='a';
        while(g!='\n') g=getchar();
        if(m[ch1]==0) { m[ch1]=node; revmap[node]=ch1; node++;}
        if(m[ch2]==0) { m[ch2]=node; revmap[node]=ch2; node++;}
        v[ m[ ch1 ] ].push_back(m[ch2]);
        v[ m[ ch2 ] ].push_back(m[ch1]);
        }
        if(f) printf("\n");
        f=1;
        while(qu--)
        {
        queue<int>q;
        ch1=getchar();
        ch2='a';
        while(ch2!=' ') ch2=getchar();
        ch2=getchar();
        g='a';
        while(g!='\n') g=getchar();
        //printf("             %c %c \n",ch1,ch2);
        char level[e+2];
        memset(level,0,sizeof(level));
        level[m[ch1]]='a';
        q.push(m[ch1]);
        //printf("             %c %c \n",ch1,ch2);
        while(!q.empty())
        {
            int x=q.front();
            if(x==m[ch2]) break;
            q.pop();
            for(int i=0;i<v[x].size();i++)
            {
                if(level[v[x][i]]==0)
                {
                    level[v[x][i]]=revmap[x];
                    q.push(v[x][i]);
                }
            }
        }
        //printf("             %c %c \n",ch1,ch2);
        char p=ch2;
        vector<char>c;
        while(p!='a')
        {
            c.push_back(p);
            //printf("                            000%c000\n",p);
            p=level[m[p]];
        }
        for(int i=c.size()-1;i>-1;i--)
        {
            cout<<c[i];
        }
        cout<<endl;
        }
    }
    return 0;
}

