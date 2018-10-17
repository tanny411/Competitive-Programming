//http://shoshikkha.com/archives/4816#comment-901
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
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        double L,nL,n,C;
        cin>>L>>n>>C;
        nL=(1.0+n*C)*L;
        double lo=0,hi=L,h=-1;
        int it=1000;
        while(it--)
        {
            double m=(lo+hi)/2;
            double r=L*L/(8.0*m) + (m/2.0);
            double theta=2*asin(L/(2.0*r));
            double S=r*theta;
            if(S>nL)hi=m;
            else if(S<nL) lo=m;
            else {h=m; break;}
        }
        cout<<"Case "<<test++<<": "<<fixed<<setprecision(10)<<h<<endl;
    }
    return 0;
}

