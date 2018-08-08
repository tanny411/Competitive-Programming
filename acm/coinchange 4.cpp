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
int n,k;
int coin[20];
vector<int>val,then;
int s;
void rec(int pos,int amount)
{
    if(pos==s) {val.pb(amount);return;}
    rec(pos+1,amount);
    if(coin[pos]*2<=k-amount) rec(pos+1,amount+2*coin[pos]);
    if(coin[pos]<=k-amount) rec(pos+1,amount+coin[pos]);
    else val.pb(amount);
}
int main()
{
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++) scanf("%d",&coin[i]);
        val.clear();
        then.clear();
        s=n/2;
        rec(0,0);
        sort(val.begin(),val.end());
        /*cout<<"val size="<<val.size()<<endl;
        for(int i=0;i<val.size();i++) cout<<" "<<val[i];
        cout<<endl;*/
        then=val;
        val.clear();
        s=n;
        rec(n/2,0);
        int f=0;
        /*cout<<"val size="<<val.size()<<endl;
        for(int i=0;i<val.size();i++) cout<<" "<<val[i];
        cout<<endl;*/
        for(int i=0;i<val.size();i++)
        {
            if(binary_search(then.begin(),then.end(),k-val[i]))
            {
                f=1;
                break;
            }
        }
        if(f) printf("Case %d: Yes\n",cas++);
        else printf("Case %d: No\n",cas++);

    }
    return 0;
}

