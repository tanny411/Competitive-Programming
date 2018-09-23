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

double a[100][101];
///ios_base::sync_with_stdio(false);
void Gaussian()
{
    int i,j,k;
    for (i=0;i<100;i++)
    {
        for (j=0;j<100;j++) {
            if (i!=j) {
                double pro=a[j][i]/a[i][i];
                for (k=0;k<=100;k++)
                    a[j][k]=a[j][k]-(a[i][k])*pro;
            }
        }
    }
}
using namespace std;
int to[102];
int main()
{
    int t,test=1;
    cin>>t;
    while(t--){
        for(int i=0;i<100;i++) to[i]=i;
        int n;
        cin>>n;
        while(n--){
            int x,y;
            cin>>x>>y;
            to[x-1]=y-1;
        }
        for(int i=0;i<100;i++) for(int j=0;j<100;j++) a[i][j]=0.0;
        for(int i=0;i<99;i++) a[i][100]=1;
        a[99][99]=1;a[99][100]=0;///at the last(winning) tile
        double p=1.0/6.0;
        for(int i=0;i<99;i++){
            a[i][i]=1.0;
            for(int j=1;j<=6;j++){
                int t=i+j;
                if(t<100) a[i][to[t]]-=p;
                else a[i][i]-=p;
            }
        }
        Gaussian();
        cout<<"Case "<<test++<<": "<<fixed<<setprecision(10)<<a[0][100]/a[0][0]<<endl;
    }
    return 0;
}
