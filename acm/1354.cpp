#include<bits/stdc++.h>
#include<cstdlib>
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
    int t,test=1;
    scanf("%d",&t);
    while(t--){
        int a,b,c,d;
        char _a[40],_b[40],_c[40],_d[40];
        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
        //cout<<"nilam";
        scanf(" %[01].%[01].%[01].%[01]",_a,_b,_c,_d);
        long p=(int)strtol(_a,NULL,2);
        long q=(int)strtol(_b,NULL,2);
        long r=(int)strtol(_c,NULL,2);
        long s=(int)strtol(_d,NULL,2);
        //cout<<p<<" "<<q<<" "<<r<<" "<<s<<endl;
        if(a==p && b==q && c==r && d==s) printf("Case %d: Yes\n",test++);
        else printf("Case %d: No\n",test++);
    }
    return 0;
}
