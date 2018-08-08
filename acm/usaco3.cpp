/*
ID: aysha.k1
TASK: friday
LANG: C++
*/

#define pb push_back
#define Pb pop_back

#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)

#define pf1(x) printf("%d\n", x)

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define llu unsigned long long

#include<limits.h>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>

#define clr( a, b )     memset((a),b,sizeof(a))
#define max3(a,b,c)     max(a,max(b,c))
#define min3(a,b,c)     min(a,min(b,c))

using namespace std;
int leap(int n)
{
    if(n%4!=0) return 0;
    else if(n%100!=0) return 1;
    else if(n%400!=0) return 0;
    else return 1;

}
int main()
{

    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);

    int n;
    cin>>n;
    int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
    vector<int>day(7);
    int y=4;
    for(int i=1900;i<1900+n;i++)
    {
        for(int j=0;j<12;j++)
        {
            int x=(j==0)?31:month[j-1];
            if(j==2 && leap(i)) x++;
            y=(y+x)%7;
            day[y]++;
        }
    }
    int f=0;
    for(int i=0;i<7;i++)
    {
        if(f) cout<<" ";
        f=1;
        cout<<day[i];
    }
    cout<<endl;
    return 0;
}

