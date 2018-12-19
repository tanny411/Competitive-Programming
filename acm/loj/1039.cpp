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

int qu;
string m[55][5];

int notvalid(string s)
{
    int i,k;
    for(i=1;i<=qu;i++)
    {
        string so=m[i][1];
        for(int j=0;j<so.length();j++)
        {
            if(so[j]==s[0])
            {
                int f=0,a;
                string p=m[i][2];
                for(a=0;a<p.length();a++)
                {
                    if(p[a]==s[1])
                    {
                        f=1;
                        break;
                    }
                }
                if(!f) continue;
                p=m[i][3];
                for(a=0;a<p.length();a++)
                {
                    if(p[a]==s[2])
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int main()
{
    //freopen("shit.txt","w",stdout);
    int test,cas=1;
    cin>>test;
    string source,dest,s;
    while(test--)
    {
        getchar();
        getchar();
        cin>>source>>dest;
        cin>>qu;
        for(int i=1;i<=qu;i++)
        {
            for(int j=1;j<=3;j++)
                cin>>m[i][j];
        }
        printf("Case %d: ",cas++);
        if( notvalid(source)|| notvalid(dest))
        {
            printf("-1\n");
            continue;
        }
        else if(source==dest)
        {
            printf("0\n");
            continue;
        }
        map<string,int>lvl;
        queue<string>q;
        q.push(source);
        while(!q.empty() && lvl[dest]==0)
        {
            string temp=q.front();
            q.pop();

         for(int x=0;x<3;x++)
         {
            string ss=temp;
            if(ss[x]=='a') ss[x]='z';
            else ss[x]--;
            if(ss!=source && lvl[ss]==0 && !notvalid(ss))
            {
                lvl[ss]=lvl[temp]+1;
                q.push(ss);
            }
            ss=temp;
            if(ss[x]=='z') ss[x]='a';
            else ss[x]++;
            if(ss!=source && lvl[ss]==0 && !notvalid(ss))
            {
                lvl[ss]=lvl[temp]+1;
                q.push(ss);
            }
        }
        }
        if(lvl[dest]==0) printf("-1");
        else printf("%d\n",lvl[dest]);
    }
    return 0;
}
