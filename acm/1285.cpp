#include<bits/stdc++.h>
#define pb push_back
#define Pb pop_back
#define ll long long
#define llu unsigned long long
#define pii pair<ll,ll>
#define ppi pair<pii,int>
#define fs first
#define sc second

using namespace std;

ll n,fx,fy,in;///first points
vector<ppi>p;

ll cw_ccw(pii o,pii a,pii b)
{
    ///is OB cw or ccw wrt OA?
    ///OA x OB >0 ccw , <0 cw , =0 collinear
    int x=(a.fs-o.fs)*(b.sc-o.sc)-(b.fs-o.fs)*(a.sc-o.sc);
    return x;
}
ll dist(pii a,pii b)
{
    return (a.fs-b.fs)*(a.fs-b.fs)+(a.sc-b.sc)*(a.sc-b.sc);
}

bool comp (ppi a, ppi b)
{
    ll x=cw_ccw(pii(fx,fy),a.fs,b.fs);
    if(x<0) return false;
    else if(x>0) return true;
    else if(dist(pii(fx,fy),a.fs)>dist(pii(fx,fy),b.fs)) return false;
    else return true;
}

void find_first_point()
{
    for(int i=0; i<n; i++)
    {
        if(p[i].fs.sc<fy)
        {
            in=i;
            fy=p[i].fs.sc;
            fx=p[i].fs.fs;
        }
        else if(p[i].fs.sc==fy && p[i].fs.fs<fx)
        {
            in=i;
            fx=p[i].fs.fs;
        }
    }
    swap(p[0],p[in]);
}
void prn()
{
    for(int i=0;i<n;i++)
    {
        if(i) cout<<" ";
        cout<<p[i].sc;
    }
    cout<<endl;
}
int main()
{
    //ios_base::sync_with_stdio(false);//RE de ken jani
    int t,test=1;
    cin>>t;
    while(t--)
    {
        p.clear();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            p.pb(ppi(pii(x,y),i));
        }
        fx=1<<30;
        fy=1<<30;
        find_first_point();
        sort(p.begin()+1,p.end(),comp);
        cout<<"Case "<<test++<<":"<<endl;
        if(cw_ccw(p[0].fs,p[1].fs,p[n-1].fs)==0) cout<<"Impossible"<<endl;
        else
        {
            for(int i=n-2;i>0;i--){
                if(cw_ccw(p[0].fs,p[n-1].fs,p[i].fs)!=0) {
                    reverse(p.begin()+(i+1),p.end());
                    break;
                }
            }
            prn();
        }
    }
    return 0;
}

