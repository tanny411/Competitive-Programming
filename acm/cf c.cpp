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
int main()
{
    int n;
    string s;
    cin>>n>>s;
    int sum=0;
    for(int i=0;i<n;i++) sum+=s[i]-'0';
    if(sum==0) {
        cout<<"YES\n";
        return 0;
    }
    for(int x=1;x<sum;x++)
    {
        int cum=0,cnt=0;
        for(int i=0;i<n;i++)
        {
            cum+=s[i]-'0';
            if(cum==x){
                while(i+1<n && s[i+1]=='0') i++;
                cum=0;
                cnt++;
                if(i==n-1 && cnt>=2){
                    cout<<"YES\n";
                    return 0;
                }
            }
            else if(cum>x) break;
        }
    }
    cout<<"NO\n";
    return 0;
}
