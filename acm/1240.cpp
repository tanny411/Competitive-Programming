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
double dis(double x1,double y1,double z1,double x2,double y2,double z2)
{
    x1-=x2;
    y1-=y2;
    z1-=z2;
    return sqrt(x1*x1+y1*y1+z1*z1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        double ax,ay,az,bx,by,bz,x,y,z;
        double axm,aym,azm;
        double axm2,aym2,azm2;
        double dist,dist2;

        cin>>ax>>ay>>az>>bx>>by>>bz>>x>>y>>z;

        double dx=bx-ax,dy=by-ay,dz=bz-az;
        double lo=0.0,hi=1.0;
        while(hi-lo>eps)
        {
            double step=(hi-lo)/3.0;
            double m=lo+step;
            double m2=hi-step;

            axm=ax+dx*m;
            aym=ay+dy*m;
            azm=az+dz*m;

            dist=dis(x,y,z,axm,aym,azm);

            axm2=ax+dx*m2;
            aym2=ay+dy*m2;
            azm2=az+dz*m2;

            dist2=dis(x,y,z,axm2,aym2,azm2);

            if(dist>dist2) lo=m;
            else hi=m2;
        }
        cout<<"Case "<<test++<<": "<<fixed<<setprecision(10)<<dist<<endl;
    }
    return 0;
}


