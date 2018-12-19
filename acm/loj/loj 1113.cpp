#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
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
#define INTMAX 1<<30
#define MOD 1000000007
#define ll long long
#define llu unsigned long long
#define eps .0000001
#define zero 0.0000000000000001
#define floatless(a,b) ( (a-b)<=eps )
#define floatequal(a,b) ( floatless(a,b) && floatless(b,a) )
#define incircle_r(a,b,c) 2*area(triangle)/perimeter(triangle)
#define circumcircle_R(a,b,c) a*b*c/sqrt( (a+b+c)*(a+b-c)*(b+c-a)*(c+a-b) )
#define circumcircle_2R_sinelaw a/sinA
#define triarea(a,b,c) sqrt( (a+b+c)*(b+c-a)*(a-b+c)*(a+b-c) )/9
#define mediantoarea(a,b,c) (4/3)*triarea(a,b,c)
using namespace std;

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",cas++);
        string s,cur,com;
        stack<string>backw,forw;
        cur="http://www.lightoj.com/";
        while(cin>>com && com!="QUIT")
        {
            if(com=="VISIT")
            {
                cin>>s;
                backw.push(cur);
                cur=s;
                forw=stack<string>();
            }
            else if(com=="BACK")
            {
                if(backw.empty())
                {
                    printf("Ignored\n");
                    continue;
                }
                else
                {
                    forw.push(cur);
                    cur=backw.top();
                    backw.pop();
                }
            }
            else if(com=="FORWARD")
            {
                if(forw.empty())
                {
                    printf("Ignored\n");
                    continue;
                }
                else
                {
                    backw.push(cur);
                    cur=forw.top();
                    forw.pop();
                }
            }
            cout<<cur<<endl;
        }
    }
    return 0;
}
