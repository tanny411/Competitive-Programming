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

using namespace std;
set<pii>p;
void gox(int xa,int ya,int xb,int yb,int dirx)
{
    for(int i=xa;;i+=dirx)
    {
        p.insert(pii(i,ya));
        if(i==xb) break;
    }
}
void goy(int xa,int ya,int xb,int yb,int diry)
{
    for(int i=ya;;i+=diry)
    {
        p.insert(pii(xb,i));
        if(i==yb) break;
    }
}
void go(int xa,int ya,int xb,int yb)
{
    if(xb!=xa) gox( xa, ya, xb, yb,(xb-xa)/abs(xb-xa));
    if(yb!=ya) goy( xa, ya, xb, yb,(yb-ya)/abs(yb-ya));
}
int main()
{
    ios_base::sync_with_stdio(false);

    int xa,xb,xc,ya,yb,yc;
    cin>>xa>>ya>>xb>>yb>>xc>>yc;

    if(xa>xb) swap(xa,xb),swap(ya,yb);
    if(xa>xc) swap(xa,xc),swap(ya,yc);
    if(xb>xc) swap(xb,xc),swap(yb,yc);

    p.insert(pii(xa,ya));
    p.insert(pii(xb,yb));
    p.insert(pii(xc,yc));

    go(xa,ya,xb,yb);
    go(xc,yc,xb,yb);

    cout<<p.size()<<endl;
    for(auto i=p.begin();i!=p.end();i++)
    {
        cout<<(*i).fs<<" "<<(*i).sc<<endl;
    }
    return 0;
}

