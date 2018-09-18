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

/**
let us divide d into d1=triangle FEX and d2=triangle FEA

a=.5*BX*h1--(i)
d1=0.5*XE*h1--(ii)

b=0.5*BX*h2--(iii)
c=0.5*XE*h2--(iv)

(i)*(iv)==(ii)*(iii)
so d1=a*c/b
-----
Use a similar reasoning, and triangles like AFE, AFC, BFE and BFC
to deduce d2.
(a+d1)/d2 = (a+b)/(c+d1+d2)
*/
    int t,test=1;
    cin>>t;
    while(t--){
        double a,b,c,d1,d2;
        cin>>a>>b>>c;
        cout<<"Case "<<test++<<": ";
        if(b==0) cout<<-1<<endl;
        else{
            d1=a*c/b;
            if(d1>=b) cout<<-1<<endl;
            else{
                d2=(a+d1)*(c+d1)/(b-d1);
                d1+=d2;
                cout<<fixed<<setprecision(10)<<d1<<endl;
            }
        }
    }
    return 0;
}
/**
4
517 647 832
916 143 61
849.09 822.31 950.86
316.95 147.46 695.55

ans : all -1
*/
