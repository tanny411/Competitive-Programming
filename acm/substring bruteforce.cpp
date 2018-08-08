#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define llu unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;

int main()
{
    string s;
    cin>>s;
    map<string,int>mp;
    for(int i=0;i<s.length();i++){
        string temp="";
        for(int j=i;j<s.length();j++){
            temp+=s[j];
            mp[temp]=1;
        }
    }
    cout<<mp.size()<<endl;
    for(auto i=mp.begin();i!=mp.end();i++){
        cout<<i->fs<<endl;
    }
    return 0;
}

