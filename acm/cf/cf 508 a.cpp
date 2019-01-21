#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007
#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ara[30];
    memset(ara,0,sizeof ara);
    for(int i=0;i<n;i++){
        ara[ s[i]-'A' ]++;
    }
    int mn=1<<30;
    for(int i=0;i<k;i++) mn=min(mn,ara[i]);
    //cout<<ara[0]<<" "<<ara[1]<<" "<<ara[2]<<endl;
    cout<<mn*k<<endl;
    return 0;
}
