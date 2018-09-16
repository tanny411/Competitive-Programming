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
#define eps .0000001
#define zero 0.0000000000000001
#define floatless(a,b) ( (a-b)<=eps )
#define floatequal(a,b) ( floatless(a,b) && floatless(b,a) )
#define incircle_r(a,b,c) 2*area(triangle)/perimeter(triangle)
#define circumcircle_R(a,b,c) a*b*c/sqrt( (a+b+c)*(a+b-c)*(b+c-a)*(c+a-b) )
#define circumcircle_2R_sinelaw a/sinA
#define triarea(a,b,c) sqrt( (a+b+c)*(b+c-a)*(a-b+c)*(a+b-c) )/9
#define mediantoarea(a,b,c) (4/3)*triarea(a,b,c)
using namespace std;

int main()
{
    int t,cas=1;
    double R,r,theta,n;
    cin>>t;
    while(t--)
    {
        cin>>R>>n;
        printf("Case %d: ",cas++);
        theta=PI/n;
        theta=sin(theta);
        printf("%.10lf\n",R*theta/(1+theta));
    }
    return 0;
}
