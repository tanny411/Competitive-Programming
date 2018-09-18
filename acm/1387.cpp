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

///

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int sum=0;
        cout<<"Case "<<test++<<":\n";
        while(n--){
            string s;
            int x;
            cin>>s;
            if(s=="donate"){
                cin>>x;
                sum+=x;
            }
            else cout<<sum<<endl;
        }
    }
    return 0;
}
