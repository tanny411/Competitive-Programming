#include<bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
using namespace std;

int main()
{
    int n;
    char ara[100000],str[1000];
    map<string,int>m;
    map<string,int>::iterator it;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(ara);
        stringstream ss;
        ss<<ara;
        ss>>str;
        m[str]++;
    }
    for(it=m.begin();it!=m.end();it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
