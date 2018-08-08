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
#define mxnd 100010
vector<int>gr[mxnd];
int cap[mxnd][mxnd];

int main()
{
    vector<int>no_tshirt(10);
    for(int i=1;i<=6;i++) cin>>no_tshirt[i];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<s.length();j++)
        {
            if(s[j]==',') s[j]=' ';
        }
        stringstream ss;
        ss<<s;
        string tee;
        while(ss>>tee)
        {
            int x;
            if(tee=="S") x=1;
            else if(tee=="M") x=2;
            else if(tee=="L") x=3;
            else if(tee=="XL") x=4;
            else if(tee=="XXL") x=5;
            else if(tee=="XXXL") x=6;
            gr[i+6].pb(x);
            gr[x].pb(i+6);
            cap[i+6][x]=1;
        }
        gr[0].pb(i+6);
        gr[i+6].pb(0);
        cap[0][i+6]=v[x];
        gr[n+7].pb(i+6);
        gr[i+6].pb(n+7);
        cap[i+6][n+7]=1;
    }

    return 0;
}

