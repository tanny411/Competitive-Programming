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
int ara[5202][5202];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        int k=n;
        for(int j=n/4-1;j>=0;j--){
            int x;
            if(isalpha(s[j])){
                x=s[j]-'A';
                x+=10;
            }
            else x=s[j]-'0';
            int cnt=4;
            while(cnt--){
                ara[i][k]=x%2;
                x/=2;
                k--;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ara[i][j]+=ara[i][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ara[i][j]+=ara[i-1][j];
        }
    }
    int ans=0;
    for(int d=1;d<=n;d++){
        if(n%d==0){
            int one=d*d;
            int flag=0;
            for(int i=d;i<=n;i+=d){
                for(int j=d;j<=n;j+=d){
                    int x=ara[i][j]-ara[i-d][j]-ara[i][j-d]+ara[i-d][j-d];
                    if(x==0 || x==one);
                    else {flag=1;break;}
                }
                if(flag) break;
            }
            if(!flag){
                ans=d;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}