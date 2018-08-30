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

///

using namespace std;
int cnt=0;
map<vector<string>,int>mp;

vector<string> moveup(vector<string>ara)
{
    for(int i=1;i<7;i++)
    {
       for(int col=0;col<7;col++)
       {
           if( (ara[i][col]=='A' && ara[i][col+1]=='A' && (ara[i-1][col]=='.' && ara[i-1][col+1]=='.'))
              || (ara[i][col]=='B' && ara[i][col+1]=='B' && (ara[i-1][col]=='.' && ara[i-1][col+1]=='.') )
              || (ara[i][col]=='C' && ara[i][col+1]=='C' && (ara[i-1][col]=='.' && ara[i-1][col+1]=='.') )
              || (ara[i][col]=='D' && ara[i][col+1]=='D' && (ara[i-1][col]=='.' && ara[i-1][col+1]=='.') ) )
           {
               int free;
               for(free=i-1;free>=0;free--)
               {
                   if(ara[free][col]=='.' && ara[free][col+1]=='.');
                   else break;
               }
               free++;
               char huu=ara[i][col];
               ara[i][col]=ara[i][col+1]=ara[i+1][col]=ara[i+1][col+1]='.';
               ara[free][col]=ara[free][col+1]=ara[free+1][col]=ara[free+1][col+1]=huu;
           }
       }
    }
    return ara;
}
vector<string> movedown(vector<string>ara)
{
    for(int i=6;i>0;i--)
    {
       for(int col=0;col<7;col++)
       {
           if( (ara[i][col]=='A' && ara[i][col+1]=='A' && (ara[i+1][col]=='.' && ara[i+1][col+1]=='.'))
              || (ara[i][col]=='B' && ara[i][col+1]=='B' && (ara[i+1][col]=='.' && ara[i+1][col+1]=='.') )
              || (ara[i][col]=='C' && ara[i][col+1]=='C' && (ara[i+1][col]=='.' && ara[i+1][col+1]=='.') )
              || (ara[i][col]=='D' && ara[i][col+1]=='D' && (ara[i+1][col]=='.' && ara[i+1][col+1]=='.') ) )
           {
               int free;
               for(free=i+1;free<8;free++)
               {
                   if(ara[free][col]=='.' && ara[free][col+1]=='.');
                   else break;
               }
               free--;
               char huu=ara[i][col];
               ara[i][col]=ara[i][col+1]=ara[i-1][col]=ara[i-1][col+1]='.';
               ara[free][col]=ara[free][col+1]=ara[free-1][col]=ara[free-1][col+1]=huu;
           }
       }
    }
    return ara;
}
vector<string> moveright(vector<string>ara)
{
    for(int col=6;col>0;col--)
    {
       for(int i=0;i<7;i++)
       {
           if( (ara[i][col]=='A' && ara[i+1][col]=='A' && (ara[i][col+1]=='.' && ara[i+1][col+1]=='.'))
              || (ara[i][col]=='B' && ara[i+1][col]=='B' && (ara[i][col+1]=='.' && ara[i+1][col+1]=='.') )
              || (ara[i][col]=='C' && ara[i+1][col]=='C' && (ara[i][col+1]=='.' && ara[i+1][col+1]=='.') )
              || (ara[i][col]=='D' && ara[i+1][col]=='D' && (ara[i][col+1]=='.' && ara[i+1][col+1]=='.') ) )
           {
               int free;
               for(free=col+1;free<8;free++)
               {
                   if(ara[i][free]=='.' && ara[i+1][free]=='.');
                   else break;
               }
               free--;
               char huu=ara[i][col];
               ara[i][col]=ara[i+1][col]=ara[i][col-1]=ara[i+1][col-1]='.';
               ara[i][free]=ara[i+1][free]=ara[i][free-1]=ara[i+1][free-1]=huu;
           }
       }
    }
    return ara;
}
vector<string> moveleft(vector<string>ara)
{
    for(int col=1;col<7;col++)
    {
       for(int i=0;i<7;i++)
       {
           if( (ara[i][col]=='A' && ara[i+1][col]=='A' && (ara[i][col-1]=='.' && ara[i+1][col-1]=='.'))
              || (ara[i][col]=='B' && ara[i+1][col]=='B' && (ara[i][col-1]=='.' && ara[i+1][col-1]=='.') )
              || (ara[i][col]=='C' && ara[i+1][col]=='C' && (ara[i][col-1]=='.' && ara[i+1][col-1]=='.') )
              || (ara[i][col]=='D' && ara[i+1][col]=='D' && (ara[i][col-1]=='.' && ara[i+1][col-1]=='.') ) )
           {
               int free;
               for(free=col-1;free>=0;free--)
               {
                   if(ara[i][free]=='.' && ara[i+1][free]=='.');
                   else break;
               }
               free++;
               char huu=ara[i][col];
               ara[i][col]=ara[i+1][col]=ara[i][col+1]=ara[i+1][col+1]='.';
               ara[i][free]=ara[i+1][free]=ara[i][free+1]=ara[i+1][free+1]=huu;
           }
       }
    }
    return ara;
}

void dfs(vector<string> ara,int in=0)
{
    if(in==0) {mp[ara]=1;
    cnt++;}
    vector<string>next;
    next=moveup(ara);
    if(mp[next]==0) dfs(next);
    next=movedown(ara);
    if(mp[next]==0) dfs(next);
    next=moveright(ara);
    if(mp[next]==0) dfs(next);
    next=moveleft(ara);
    if(mp[next]==0) dfs(next);
}
int main()
{
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t,tst=1;
    cin>>t;
    while(t--)
    {
        vector<string> ara(8),test;
        for(int i=0;i<8;i++) cin>>ara[i];
        //test=movedown(ara);
        //cout<<endl;
        //for(int i=0;i<8;i++) cout<<test[i]<<endl;
        cnt=0;
        dfs(ara,-1);
        cout<<"Case "<<tst++<<": "<<cnt<<endl;
    }
    return 0;
}
/*
1
AA..CC..
AA..CC..
BB..DD..
BB.#DD..
........
........
....#...
........

*/
/*
1
DD......
DD.#...#
.#..#...
.#BB....
..BB.AA.
.....AA.
CC.#....
CC...#.#

434
*/
