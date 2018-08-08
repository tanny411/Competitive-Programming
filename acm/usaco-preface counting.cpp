/*
ID: aysha.k1
LANG: C++11
TASK: preface
*/
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

string doo(int x)
{
    string s;
    int m=x/1000;
    x%=1000;
    while(m--) s+='M';

    m=x/500;
    x%=500;
    while(m--) s+='D';

    m=x/100;
    x%=100;
    if(m==4) {s+="CD";m=0;}
    while(m--) s+='C';

    m=x/50;
    x%=50;
    while(m--) s+='L';


    m=x/10;
    x%=10;
    if(m==4) {s+="XL";m=0;}
    while(m--) s+='X';


    m=x/5;
    x%=5;
    while(m--) s+='V';


    m=x;
    if(m==4) {s+="IV";m=0;}
    while(m--) s+='I';
    string h;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(i-2>=0)
        {
            string t;t+=s[i];t+=s[i-1];t+=s[i-2];
            int f=0;
            if(t=="VIV") h+="IX";
            else if(t=="LXL") h+="XC";
            else if(t=="DCD") h+="CM";
            else {f=1;h+=s[i];}
            if(f==0) i-=2;
        }
        else {h+=s[i];}
    }
    return h;
}

int main()
{
    //freopen("preface.in","r",stdin);
    //freopen("preface.out","w",stdout);
    int n;
    cin>>n;
    map<char,int>m;
    for(int i=1;i<=n;i++)
    {
        string s=doo(i);
        //cout<<s<<endl;
        for(int j=0;j<s.length();j++)
        {
            m[s[j]]++;
        }
    }
    vector<int>v;
    int f=0;
    if(f || m['M']) {v.pb(m['M']);f=1;}
    if(f || m['D']) {v.pb(m['D']);f=1;}
    if(f || m['C']) {v.pb(m['C']);f=1;}
    if(f || m['L']) {v.pb(m['L']);f=1;}
    if(f || m['X']) {v.pb(m['X']);f=1;}
    if(f || m['V']) {v.pb(m['V']);f=1;}
    if(f || m['I']) {v.pb(m['I']);f=1;}
    int j=0;
    for(int i=v.size()-1;i>=0;i--,j++)
    {
        if(j==0) cout<<"I ";
        if(j==1) cout<<"V ";
        if(j==2) cout<<"X ";
        if(j==3) cout<<"L ";
        if(j==4) cout<<"C ";
        if(j==5) cout<<"D ";
        if(j==6) cout<<"M ";
        cout<<v[i]<<endl;
    }
    return 0;
}

