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
int n,q;
int ara[30003];
int cnt[1000005];
vector<pair<pii,int> >Q;
int sq;
bool cmp(pair<pii,int> a ,pair<pii,int> b)
{
    if(a.fs.fs/sq!=b.fs.fs/sq) return a.fs.fs/sq<b.fs.fs/sq;
    else return a.fs.sc<b.fs.sc;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&ara[i]);
    Q.clear();
    int c=0;
    scanf("%d",&q);
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        Q.pb({{x-1,y-1},c++});
    }
    sq=sqrt(n);
    sort(Q.begin(),Q.end(),cmp);
    int huu[Q.size()];
    int L=0,R=0,ans=0;
    for(int i=0;i<c;i++)
    {
        int cl=Q[i].fs.fs;
        int cr=Q[i].fs.sc;
        while(cl<L)
        {
            if(cnt[ara[cl]]==0) ans++;
            cnt[ara[cl]]++;
            cl++;
        }
        if(cl>=L) cl--;
        while(cl>=L)
        {
            cnt[ara[cl]]--;
            if(cnt[ara[cl]]==0) ans--;
            cl--;
        }
        while(R<cr)
        {
            if(cnt[ara[cr]]==0) ans++;
            cnt[ara[cr]]++;
            cr--;
        }
        if(R>=cr) cr++;
        while(R>=cr)
        {
            cnt[ara[cr]]--;
            if(cnt[ara[cr]]==0) ans--;
            cr++;
        }
        huu[Q[i].sc]=ans;
    }
    for(int i=0;i<c;i++)
    {
        printf("%d\n",huu[i]);
    }
    return 0;
}

