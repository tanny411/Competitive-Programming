#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define LLU unsigned long long

#define fs first
#define sc second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n,minX,maxX;
        cin>>n>>minX>>maxX;
        vector<ll>w(n+1),b(n+1);
        for(int i=0;i<n;i++) cin>>w[i]>>b[i];
        int even=0;
        int odd=1;
        minX--;
        int neven=maxX/2 - minX/2;
        int nodd=maxX/2 + (maxX%2==1) - minX/2 - (minX%2==1);
        for(int i=0;i<n;i++)
        {
            even=((even*w[i])%2 + b[i])%2;
            odd=((odd*w[i])%2 + b[i])%2;
        }
        int spammer=0,notspammer=0;
        if(even) spammer+=neven;
        if(odd) spammer+=nodd;
        if(!even) notspammer+=neven;
        if(!odd) notspammer+=nodd;
        cout<<notspammer<<" "<<spammer<<endl;
    }
    return 0;
}

