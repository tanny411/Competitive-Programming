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
/*
5
5711 3044 477 2186 3257 7746
3233 31 3336 1489 1775 134
453 4480 1137 6678 2395 5716
8757 2995 4807 8660 2294 5429
4439 4272 1366 8741 6820 9145
*/
using namespace std;

int main()
{
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        double ox,oy,ax,ay,bx,by;
        cin>>ox>>oy>>ax>>ay>>bx>>by;
        ax-=ox;bx-=ox;
        ay-=oy;by-=oy;
        double r=sqrt(bx*bx+by*by);
        cout<<fixed<<setprecision(10)<<"Case "<<cas++<<": "<< r*acos((ax*bx+ay*by)/(bx*bx+by*by)) <<endl;
    }
    return 0;
}

