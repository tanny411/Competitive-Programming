//ternary search
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

#define eps 1e-9

using namespace std;
double dis(double x1,double y1,double x2,double y2)
{
    x1-=x2;
    y1-=y2;
    return sqrt(x1*x1+y1*y1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        double ax,ay,bx,by,cx,cy,dx,dy;
        double axm,aym,cxm,cym;
        double axm2,aym2,cxm2,cym2;
        double dist,dist2;

        cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;

        double dx1=bx-ax,dy1=by-ay,dx2=dx-cx,dy2=dy-cy;
        ///slopes, didnt divide, cuz could be vertical lines
        double lo=0.0,hi=1.0;
        while(hi-lo>eps)
        {
            double step=(hi-lo)/3.0;
            double m=lo+step;
            double m2=hi-step;

            axm=ax+dx1*m;
            aym=ay+dy1*m;
            cxm=cx+dx2*m;
            cym=cy+dy2*m;

            dist=dis(axm,aym,cxm,cym);

            axm2=ax+dx1*m2;
            aym2=ay+dy1*m2;
            cxm2=cx+dx2*m2;
            cym2=cy+dy2*m2;

            dist2=dis(axm2,aym2,cxm2,cym2);

            if(dist>dist2) lo=m;
            else hi=m2;
        }
        cout<<"Case "<<test++<<": "<<fixed<<setprecision(10)<<dist<<endl;
    }
    return 0;
}

