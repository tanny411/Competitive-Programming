#include<bits/stdc++.h>
#define pii pair<ll,ll>
#define fs first
#define sc second
#define ll long long
using namespace std;

pii extendedEuclid(ll a,ll b)
{
    if(b==0) return pii(1,0);
    else
    {
        pii d=extendedEuclid(b,a%b);
        return pii(d.sc,d.fs-d.sc*(a/b));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        ll a,b,c,x1,y1,x2,y2;
        cin>>a>>b>>c>>x1>>x2>>y1>>y2;
        c=-c;
        if(a<0)///dividing inequality with negative number reverses the signs(< & >)
        {
            a=-a;
            x1=-x1;
            x2=-x2;
            swap(x1,x2);
        }
        if(b<0)
        {
            b=-b;
            y1=-y1;
            y2=-y2;
            swap(y1,y2);
        }
        ll d=__gcd(a,b);
        if(d==0){
            if(c==0) cout<<"Case "<<test++<<": "<<(x2-x1+1)*(y2-y1+1)<<endl;
            else cout<<"Case "<<test++<<": 0"<<endl;
        }
        else if(c%d!=0)
        {
            cout<<"Case "<<test++<<": 0"<<endl;
        }
        else if(b==0)
        {
            ///we can put any value for y as 0*anything=0
            if(c/a>=x1 && c/a<=x2) cout<<"Case "<<test++<<": "<<(y2-y1+1)<<endl;
            else cout<<"Case "<<test++<<": 0"<<endl;
        }
        else if(a==0)
        {
            if(c/b>=y1 && c/b<=y2) cout<<"Case "<<test++<<": "<<(x2-x1+1)<<endl;
            else cout<<"Case "<<test++<<": 0"<<endl;
        }
        else{
            a/=d;
            b/=d;
            c/=d;
            pii p=extendedEuclid(a,b);
            p.fs*=c;
            p.sc*=c;
            //cout<<"coefficients "<<p.fs<<" "<<p.sc<<endl;

            ///x and y high, low
            ///have to write floor explicitly
            ///else negative number floor not done properly
            ll xl,xh,yl,yh;
            xh=floor((p.fs-x1)/ (1.0*b) );
            xl=ceil((p.fs-x2)/ (1.0*b) );
            yh=floor((y2-p.sc)/ (1.0*a) );
            yl=ceil((y1-p.sc)/ (1.0*a) );

            //cout<<xl<<" "<<xh<<endl;
            //cout<<yl<<" "<<yh<<endl;

            xh=min(xh,yh);
            xl=max(xl,yl);
            ll ans=max((xh-xl+1),0ll);

            cout<<"Case "<<test++<<": "<<ans<<endl;
        }
    }
    return 0;
}

/**
Input:
19
1 -2 -29 -36 23 -35 -4
-2 1 -50 -46 -28 -41 -39
-2 -1 -21 14 24 3 16
-2 -2 -48 -12 10 -29 -27
-1 -2 -47 -21 39 20 31
-1 1 -36 9 12 -48 14
-2 -2 -20 -21 30 -43 -10
0 0 45 22 28 -5 50
-1 0 29 11 40 16 22
-1 -2 -35 18 25 -41 37
63125769 40113320 -16531647 -56280824 28391667 8698147 97138240
7554218 73321470 31103534 -27761990 44636308 -70455302 43845195
24609000 47999742 46028640 -83110292 60237765 -64566874 10862683
-6 38 -642 392 411 77 98
-74 -62 -380 -194 -148 163 220
-21 70 665 371 392 80 117
-896 976 47272032 37875461 37885074 34720255 34732090
-414 92 32907664 -6358268 -6344601 -28956763 -28948494
-283 549 -3355322 2995137 3007335 1542739 1555837
Output:
Case 1: 29
Case 2: 1
Case 1: 0
Case 2: 3
Case 3: 0
Case 4: 0
Case 5: 31
Case 6: 0
Case 1: 7
Case 2: 4
Case 1: 1
Case 2: 2
Case 3: 10
Case 4: 1
Case 5: 1
Case 6: 2
Case 7: 158
Case 8: 919
Case 9: 20
*/
