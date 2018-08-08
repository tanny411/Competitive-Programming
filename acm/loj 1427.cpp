#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define LL long long
#define LLU unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;
//#define mxs 250002
char text[1000002];
char ara[502][502];

int ans[502];

void AhoCorasick(int n,int mxs)
{
    int trie[mxs][26];
    int f[mxs];
    memset(trie,-1,sizeof trie);
    bitset<502>out[mxs];
    memset(ans, 0, sizeof ans);

    int states=1;

    for(int i=0;i<n;i++)
    {
        int node=0;
        for(int j=0;ara[i][j];j++)
        {
            int ch=ara[i][j]-'a';
            if(trie[node][ch]==-1) trie[node][ch]=states++;
            node=trie[node][ch];
        }
        out[node].set(i);
    }

    for(int i=0;i<26;i++) if(trie[0][i]==-1) trie[0][i]=0;

    ///failure

    memset(f,-1,sizeof f);
    queue<int>q;

    for(int i=0;i<26;i++)
    {
        if(trie[0][i]!=0) q.push(trie[0][i]),f[trie[0][i]]=0;
    }

    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        for(int i=0;i<26;i++)
        {
            if(trie[node][i]!=-1)
            {
                int failure=f[node];

                while(trie[failure][i]==-1) failure=f[failure];

                failure=trie[failure][i];
                f[trie[node][i]]=failure;

                out[trie[node][i]]|=out[failure];

                q.push(trie[node][i]);
            }
        }
    }

    int node=0;
    for(int i=0;text[i];i++)
    {
        int ch=text[i]-'a';
        while(trie[node][ch]==-1) node=f[node];
        node=trie[node][ch];

        if(out[node]!=0) for(int k=0;k<n;k++) if(out[node][k]) ans[k]++;
    }

    return;
}

int main()
{
    double cl=clock();
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        getchar();
        gets(text);
        int a=0;
        for(int i=0;i<n;i++)
        {
            gets(ara[i]);
            a+=strlen(ara[i]);
        }
        AhoCorasick(n,a+3);
        printf("Case %d:\n",cas++);
        for(int i=0;i<n;i++) printf("%d\n",ans[i]);
    }
    //printf("%lf\n",clock()-cl);
    return 0;
}

