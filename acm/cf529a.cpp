#include<iostream>
#include<string>

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
    //ios_base::sync_with_stdio(false);
    string s;
    int n;
    cin>>n>>s;
    for(int i=0,cnt=2;i<n;cnt++)
    {
        cout<<s[i];
        i+=cnt;
    }
    return 0;
}

