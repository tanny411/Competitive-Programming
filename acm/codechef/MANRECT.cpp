#include<bits/stdc++.h>
#define pb push_back
#define Pb pop_back
#define fs first
#define sc second
#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define MOD 1000000007
#define LL long long
#define LLU unsigned long long
#define eps .0000001
#define zero 0.0000000000000001
#define floatless(a,b) ( (a-b)<=eps )
#define floatequal(a,b) ( floatless(a,b) && floatless(b,a) )
#define incircle_r(a,b,c) 2*area(triangle)/perimeter(triangle)
#define circumcircle_R(a,b,c) a*b*c/sqrt( (a+b+c)*(a+b-c)*(b+c-a)*(c+a-b) )
#define circumcircle_2R_sinelaw a/sinA
#define triarea(a,b,c) sqrt( (a+b+c)*(b+c-a)*(a-b+c)*(a+b-c) )/9
#define mediantoarea(a,b,c) (4/3)*triarea(a,b,c)
/*----------------------Graph Moves----------------*/
//const int fx[]= {+1,-1,+0,+0};
//const int fy[]= {+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

using namespace std;
struct line{
    LL slope;
    LL intercept;
};
int main()
{
    int t,cas=1;
    cin>>t;
    while(t--){
        LL x;
        cout<<"Q 0 0"<<endl;
        cin>>x;
        // x=3;
        
        line line1;
        line1.slope=-1;
        line1.intercept=x;

        cout<<"Q 1000000000 0"<<endl;
        cin>>x;
        // x=999999999;

        line line2;
        line2.slope=1;
        line2.intercept=x-1000000000;

        cout<<"Q 1000000000 1000000000"<<endl;
        cin>>x;
        // x=1999999993;
        
        line line3;
        line3.slope=-1;
        line3.intercept=2000000000-x;

        cout<<"Q 0 1000000000"<<endl;
        cin>>x;
        //x=999999997;
        
        line line4;
        line4.slope=1;
        line4.intercept=1000000000-x;

        LL L,R,U,D,y,X;
        
        // cout<<"The lines are: \n";
        // cout<<"line 1 -- slope "<<line1.slope<<" intercept "<<line1.intercept<<endl;
        // cout<<"line 2 -- slope "<<line2.slope<<" intercept "<<line2.intercept<<endl;
        // cout<<"line 3 -- slope "<<line3.slope<<" intercept "<<line3.intercept<<endl;
        // cout<<"line 4 -- slope "<<line4.slope<<" intercept "<<line4.intercept<<endl;

        x=(line2.intercept-line3.intercept)/(line3.slope-line2.slope);
        y=line2.slope*x+line2.intercept;
        x=min(x,(LL)1000000000);
        y=min(y,(LL)1000000000);
        cout<<"Q "<<x<<" "<<y<<endl;
        cin>>X;
        R=x-X;

        x=(line4.intercept-line3.intercept)/(line3.slope-line4.slope);
        y=line4.slope*x+line4.intercept;
        x=min(x,(LL)1000000000);
        y=min(y,(LL)1000000000);
        cout<<"Q "<<x<<" "<<y<<endl;
        cin>>X;
        U=y-X;

        D=line2.slope*R+line2.intercept;
        L=(D-line1.intercept)/line1.slope;


        cout<<"A "<<L<<" "<<D<<" "<<R<<" "<<U<<endl;
        cin>>X;
        if(X<0) return 0;
    }
    return 0;
}