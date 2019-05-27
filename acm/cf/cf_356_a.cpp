#include<bits/stdc++.h>
#define pb push_back
#define Pb pop_back
#define fs first
#define sc second
#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define MOD 1000000007
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
string ara[1000];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    int cnt=0;
    if(n<=2) {
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<n-1;i++){
        for(int j=1;j<n-1;j++){
            if(ara[i-1][j-1]=='X' && ara[i-1][j+1]=='X' &&ara[i+1][j-1]=='X' &&ara[i+1][j+1]=='X' && ara[i][j]=='X') cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}