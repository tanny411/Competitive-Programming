//http://lbv-pc.blogspot.com/2012/07/treblecross.html
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
int gr[210],n;
string s;
void pre()
{
    gr[0]=0;
    for(int i=1;i<=200;i++){
        set<int>s;
        for(int j=1;j<=i;j++)
        {
            s.insert(gr[max(0,j-3)]^gr[max(0,i-j-2)]);
        }
        int ret=0;
        while(s.find(ret)!=s.end())ret++;
        gr[i]=ret;
    }
}
bool solve(int ind)
{
    string temp=s;
    temp[ind]='X';
    ///trivial wins
    for(int i=0;i<n-2;i++){
        if(temp[i]=='X' && temp[i+1]=='X' && temp[i+2]=='X') return true;
    }
    ///trivial losses
    for(int i=0;i<n;i++)
    {
        if(i<n-1 && temp[i]=='X' && temp[i+1]=='X') return false;
        if(i<n-2 && temp[i]=='X' && temp[i+2]=='X') return false;
    }
    ///grundy time!!
    int start=0,last,ans=0;
    for(int i=0;i<n;i++)
    {
        if(temp[i]=='X'){
            last=i-3;
            ans^=gr[max(0,last-start+1)];
            start=i+3;
        }
    }
    ans^=gr[max(0,n-1-start+1)];
    return ans==0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    pre();
    //for(int i=0;i<50;i++) cout<<" "<<gr[i];
    int t,test=1;
    cin>>t;
    while(t--)
    {
        cin>>s;
        n=s.length();
        vector<int>v;
        int st=0,en;
        for(int i=0;i<n;i++){
            if(s[i]=='.' && solve(i)) v.pb(i+1);
        }
        if(v.empty()) cout<<"LOSING\n";
        else cout<<"WINNING\n";
        for(int i=0;i<v.size();i++) {if(i) cout<<" "; cout<<v[i];}
        cout<<endl;
    }
    return 0;
}


