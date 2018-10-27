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

using namespace std;
bool cmp(pii a,pii b)
{
    if(a.sc!=b.sc) return a.sc>b.sc;
    else return a.fs<b.fs;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pii>v[4];
        while(n--)
        {
            int c,l,x;
            cin>>c>>l>>x;
            v[l].pb({c,x});
        }
        for(int i=1;i<=3;i++) sort(v[i].begin(),v[i].end(),cmp);
        for(int i=1;i<=3;i++) cout<<v[i][0].sc<<" "<<v[i][0].fs<<endl;
    }
    return 0;
}

