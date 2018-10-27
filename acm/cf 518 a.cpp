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

int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    LL n,m,k,l;
    cin>>n>>m>>k>>l;
    LL need=k+l;
    LL each=need/m;
    LL tot=each*m;
    if(tot<need) tot+=m,each++;
    if(tot>n || need>n) cout<<-1;
    else cout<<each;
    return 0;
}

