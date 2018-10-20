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


#define fs first
#define sc second

///ios_base::sync_with_stdio(false)

using namespace std;

/**
     * To get parent
     * 1) 2's complement to get minus of index
     * 2) AND this with index
     * 3) Subtract that from index
     */
int getParent(int ind)
{
    return ind=ind - (ind & -ind);
}

/**
     * To get next
     * 1) 2's complement of get minus of index
     * 2) AND this with index
     * 3) Add it to index
     */
int getNext(int ind)
{
    return ind=ind + (ind & -ind);
}
#define maxn 1000+5

int n;
vector<int>ara(maxn),tree(maxn);

void update(int ind,int val)
{
    ind++;
    while(ind<n+1)
    {
        tree[ind]+=val;
        ind=getNext(ind);
    }
}

int getSum(int ind) ///cummulative sum from 0 to ind
{
    ind++;
    int sum=0;
    while(ind>0)
    {
        sum+=tree[ind];
        ind=getParent(ind);
    }
    return sum;
}

void buildTree()
{
    ///first tree is initialised to 0;
    ///do update operation for all nodes
    for(int i=0;i<n;i++)
    {
        update(i,ara[i]);
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ara[i];
    }
    buildTree();
    cout<<getSum(8)<<" "<<getSum(4)<<endl;
    update(3,7);
    cout<<getSum(8)<<" "<<getSum(4)<<endl;
    update(2,8);
    cout<<getSum(8)<<" "<<getSum(4)<<endl;
    return 0;
}

