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

#define x first
#define y second
#define Point pii

using namespace std;
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x)-(q.x - p.x) * (r.y - q.y);
    return val;
}
bool intersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if ( ( (o1>0 && o2<0) || (o1<0 && o2>0) ) && ( (o3>0 && o4<0) || (o3<0 && o4>0) ) ) return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int a,b,c,d,e,f,L,R;
        cin>>a>>b>>c>>d>>e>>f>>L>>R;
        if(R>L) swap(L,R);
        int flag=0,glag=0;
        if(b>a) {swap(a,b);flag=1;}
        if(e>d) {swap(e,d);glag=1;}
        if(L>=max(a,d) && R>=max(b,e));
        else{cout<<-1<<endl;continue;}
        pii A,B,C,D,E,F;
        B=pii(a,0);
        A=pii(0,b);
        C=pii(0,0);
        F=pii(L,R);
        D=pii(L,R-e);
        E=pii(L-d,R);
        if(flag) swap(A,B);
        if(glag) swap(D,E);
        cout<<A.x<<" "<<A.y<<endl;
        cout<<B.x<<" "<<B.y<<endl;
        cout<<C.x<<" "<<C.y<<endl;
        cout<<D.x<<" "<<D.y<<endl;
        cout<<E.x<<" "<<E.y<<endl;
        cout<<F.x<<" "<<F.y<<endl;
    }
    return 0;
}

