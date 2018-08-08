/*
ID: aysha.k1
TASK: beads
LANG: C++
*/

//#include<bits/stdc++.h>

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

int main()
{
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);

    string a;
    int n;

    cin>>n>>a;
    a+=a;
    n+=n;
    int f=0;
    vector<int>flag(n+3);
    for(int i=0;i<n;i++)
    {
        if(a[i]=='b')
        {
            f=1;
            flag[i]=1;
            while(a[i]=='b' || a[i]=='w')
            {
                i++;
            }
        }
    }
    if(!f) { cout<<n/2<<endl; return 0; }
    int mx=-1<<30;
    for(int i=0;i<n;i++)
    {
        if(flag[i])
        {
            int x=i;
            int cnt=0;
            int j=i-1;
            while(j>-1 && a[j]=='w')
            {
                j--;
                cnt++;
            }
            i++;
            while(i<n && flag[i]==0) i++;
            cnt+=(i-x);
            i--;
            //cout<<"    "<<cnt<<endl;
            if(cnt>n/2) continue;
            mx=max(mx,cnt);
        }
    }
    //for(int i=0;i<n;i++) cout<<flag[i];
    //cout<<endl;


    f=0;
    //memset(flag,0,sizeof(flag));
    fill(flag.begin(),flag.end(),0);
    for(int i=0;i<n;i++)
    {
        if(a[i]=='r')
        {
            f=1;
            flag[i]=1;
            while(a[i]=='r' || a[i]=='w')
            {
                i++;
            }
        }
    }
    if(!f) { cout<<n/2<<endl; return 0; }
    for(int i=0;i<n;i++)
    {
        if(flag[i])
        {
            int x=i;
            int cnt=0;
            int j=i-1;
            while(j>-1 && a[j]=='w')
            {
                j--;
                cnt++;
            }
            i++;
            while(i<n && flag[i]==0) i++;
            cnt+=(i-x);
            i--;
            if(cnt>n/2) continue;
            //cout<<"    "<<cnt<<endl;
            mx=max(mx,cnt);
        }
    }














    cout<<mx<<endl;
    return 0;
}
