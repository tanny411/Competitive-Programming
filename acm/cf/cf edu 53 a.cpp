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

    int t,n,test=1;
    string s;

    cin>>n>>s;

    for(int i=0;i<n;i++)
    {
        string temp;
        vector<int>v(30);
        int mx=0;
        int len=0;
        for(int j=i,len=1;j<n;j++,len++)
        {
            temp+=s[j];
            v[ s[j]-'a' ]++;
            mx=max(mx,v[ s[j]-'a' ]);
            int l=len/2;
            if(mx<=l)
            {
                cout<<"YES"<<endl;
                cout<<temp<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}

