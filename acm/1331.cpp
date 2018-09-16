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
    int t,test=1;
    cin>>t;
    while(t--)
    {
        double r1,r2,r3;
        cin>>r1>>r2>>r3;
        if(r1==0 || r2==0 || r3==0) {
            cout<<"Case "<<test++<<": 0"<<endl;
            continue;
        }
        double a=r1+r2;
        double b=r3+r2;
        double c=r1+r3;
        //cout<<"Sides = "<<a<<" "<<b<<" "<<c<<endl;
        double A=acos((b*b+c*c-a*a)/(2*b*c) );
        double B=acos((a*a+c*c-b*b)/(2*a*c) );
        double C=acos((b*b+a*a-c*c)/(2*b*a) );
        //cout<<"Angles = "<<A<<" "<<B<<" "<<C<<endl;
        double ans=0.5*a*b*sin(C);
        A=r3*r3*A/2.0;
        B=r1*r1*B/2.0;
        C=r2*r2*C/2.0;
        ans=ans-A-B-C;
        cout<<"Case "<<test++<<": "<<fixed<<setprecision(10)<<ans<<endl;
    }
    return 0;
}
