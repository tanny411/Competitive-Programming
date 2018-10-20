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
int n,m;
int inside(pii x)
{
    if(x.fs>=0 && x.fs<n && x.sc>=0 && x.sc<m) return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int d1[n+5][m+5],d2[n+5][m+5],ara[n+5][m+5];
        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;
            for(int j=0; j<m; j++)
                ara[i][j]=d2[i][j]=d1[i][j]=(s[j]=='1');
        }
        ///first diagonal
        for(int i=0; i<n; i++)
        {
            for(int x=i-1,y=1; x>=0 && y<m; x--, y++)
            {
                d1[x][y]+=d1[x+1][y-1];
            }
        }
        for(int j=1; j<m; j++)
        {
            for(int x=n-2,y=j+1; x>=0 && y<m; x--, y++)
            {
                d1[x][y]+=d1[x+1][y-1];
            }
        }
        ///second diagonal
        for(int j=0; j<m; j++)
        {
            for(int x=1,y=j+1; x<n && y<m; x++,y++)
            {
                d2[x][y]+=d2[x-1][y-1];
            }
        }
        for(int i=1; i<n; i++)
        {
            for(int x=i+1,y=1; x<n && y<m; x++,y++)
            {
                d2[x][y]+=d2[x-1][y-1];
            }
        }

        /*cout<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                cout<<d1[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                cout<<d2[i][j];
            }
            cout<<endl;
        }
        cout<<endl;*/

        for(int d=1; d<=n+m-2; d++)
        {
            int ans=0;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if(ara[i][j]==0) continue;
                    pii upl=pii(i-d,j);
                    pii upr=pii(i-d,j);
                    pii downl=pii(i+d,j);
                    pii downr=pii(i+d,j);
                    pii leftu=pii(i,j-d);
                    pii leftd=pii(i,j-d);
                    pii rightu=pii(i,j+d);
                    pii rightd=pii(i,j+d);
                    if(upl.fs<0)
                    {
                        upl.sc-=-upl.fs;
                        upr.sc+=-upl.fs;
                        upl.fs=0;
                        upr.fs=0;
                    }
                    if(downl.fs>=n)
                    {
                        downl.sc+=n-1-downl.fs;
                        downr.sc-=n-1-downl.fs;
                        downl.fs=n-1;
                        downr.fs=n-1;
                    }
                    if(rightu.sc>=m)
                    {
                        rightu.fs+=m-1-rightu.sc;
                        rightd.fs-=m-1-rightu.sc;
                        rightu.sc=m-1;
                        rightd.sc=m-1;
                    }
                    if(leftu.sc<0)
                    {
                        leftu.fs+=leftu.sc;
                        leftd.fs-=leftu.sc;
                        leftu.sc=0;
                        leftd.sc=0;
                    }

                    if(inside(upl) && upl==upr) ans-=ara[upl.fs][upl.sc];
                    if(inside(downl) && downl==downr) ans-=ara[downl.fs][downl.sc];
                    if(inside(rightu) && rightd==rightu) ans-=ara[rightu.fs][rightu.sc];
                    if(inside(leftu) && leftu==leftd) ans-=ara[leftu.fs][leftu.sc];

                    if(inside(upr)&&inside(rightu)){
                        upr.fs--;
                        upr.sc--;
                        ans+=d2[rightu.fs][rightu.sc]-(inside(upr)?d2[upr.fs][upr.sc]:0);
                        //cout<<"1 - d = "<<d<<" ans = "<<ans<<endl;
                    }
                    if(inside(upl)&&inside(leftu)){
                        leftu.fs++;
                        leftu.sc--;
                        ans+=d1[upl.fs][upl.sc]-(inside(leftu)?d1[leftu.fs][leftu.sc]:0);
                        //cout<<"leftu "<<leftu.fs<<" "<<leftu.sc<<endl;
                        //cout<<"upl "<<upl.fs<<" "<<upl.sc<<endl;
                        //cout<<"2 - d = "<<d<<" cumu = "<<d1[upl.fs][upl.sc]-(inside(leftu)?d1[leftu.fs][leftu.sc]:0)<<endl;
                    }
                    if(inside(downl)&&inside(leftd)){
                        leftd.fs--;
                        leftd.sc--;
                        ans+=d2[downl.fs][downl.sc]-(inside(leftd)?d2[leftd.fs][leftd.sc]:0);
                        //cout<<"3 - d = "<<d<<" ans = "<<ans<<endl;
                    }
                    if(inside(downr)&&inside(rightd)){
                        downr.fs++;
                        downr.sc--;
                        ans+=d1[rightd.fs][rightd.sc]-(inside(downr)?d1[downr.fs][downr.sc]:0);
                        //if(ans==-1) cout<<"4 - d = "<<d<<" ans = "<<ans<<" i,j "<<i<<" "<<j<<endl;
                    }
                    //if(d!=3) continue;
                    //cout<<"leftu "<<leftu.fs<<" "<<leftu.sc<<endl;
                    //cout<<"leftd "<<leftd.fs<<" "<<leftd.sc<<endl;
                    //cout<<"upl "<<upl.fs<<" "<<upl.sc<<endl;
                    //cout<<"rightd "<<rightd.fs<<" "<<rightd.sc<<endl;
                    //cout<<"downr "<<downr.fs<<" "<<downr.sc<<endl;
                    //cout<<"downl "<<downl.fs<<" "<<downl.sc<<endl;
                    //cout<<"d = "<<d<<" ans = "<<ans<<endl;
                }
            }
            if(d>1) cout<<" ";
            cout<<ans/2;
        }
        cout<<endl;
    }
    return 0;
}

