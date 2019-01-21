#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007
#define eps 1e-10
#define LL long long
#define LLU unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;

int main()
{
    double rot=PI/4.0;
    double s=sin(rot);
    double c=cos(rot);
    double n,d;
    cin>>n>>d;
    //double xbl=d*s,ybl=d*c;
    double xbl=d*c,ybl=-d*s;
    //double xur=n*c+(n-d)*s,yur=-n*s+(n-d)*c;
    double xur=(n-d)*c+n*s,yur=-(n-d)*s+n*c;
    //cout<<xbl<<" "<<ybl<<" "<<xur<<" "<<yur<<endl;
    int m;
    cin>>m;
    while(m--)
    {
        double tx,ty,x,y;
        cin>>tx>>ty;
        x=tx*c+ty*s;
        y=-tx*s+ty*c;
        //cout<<x<<" "<<y<<endl;
        if(x+eps>=xbl && x<=xur+eps && y+eps>=ybl && y<=eps+yur) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
