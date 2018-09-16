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
struct cube{
    int a,b,c;
    int fa,fb,fc;
    bool operator<(cube x) const{
        if(x.a!=a) return a<x.a;
        else if(x.b!=b) return b<x.b;
        else if(x.c!=c)return c<x.c;
        else if(x.fa!=fa)return fa<x.fa;
        else if(x.fb!=fb)return fb<x.fb;
        else return fc<x.fc;
    }
};
int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<cube>v(n);
        for(int i=0;i<n;i++) cin>>v[i].a>>v[i].b>>v[i].c>>v[i].fa>>v[i].fb>>v[i].fc;
        sort(v.begin(),v.end());
        cube ini,fin;
        fin.a=fin.b=fin.c=1<<30;
        ini.a=ini.b=ini.c=0;
        int oops=1;
        for(int i=0;i<n && oops;i++){
            if(v[i].a<=fin.a && v[i].b<=fin.b && v[i].c<=fin.c) {

                ini.a=max(ini.a,v[i].a);
                ini.b=max(ini.b,v[i].b);
                ini.c=max(ini.c,v[i].c);

                fin.a=min(fin.a,v[i].fa);
                fin.b=min(fin.b,v[i].fb);
                fin.c=min(fin.c,v[i].fc);

                //cout<<"ashche\n";
                //cout<<ini.a<<" "<<ini.b<<" "<<ini.c<<" --  "<<fin.a<<" "<<fin.b<<" "<<fin.c<<endl;
            }
            else oops=0;
        }
        if(oops) cout<<"Case "<<test++<<": "<<(fin.b-ini.b)*(fin.c-ini.c)*(fin.a-ini.a)<<endl;
        else cout<<"Case "<<test++<<": 0"<<endl;
    }
    return 0;
}
