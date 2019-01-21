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
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++)
    {
        if(i==n-1)
        {
            s.erase(s.begin()+i);
            break;
        }
        else if(s[i]>s[i+1]){
            s.erase(s.begin()+i);
            break;
        }
    }
    cout<<s<<endl;
    return 0;
}

