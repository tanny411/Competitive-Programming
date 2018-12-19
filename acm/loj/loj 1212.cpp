//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<deque>
#include<string>

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
#define prf printf("The queue is full\n")
#define pre printf("The queue is empty\n")
using namespace std;

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        printf("Case %d:\n",cas++);
        int siz,q;
        scanf("%d %d",&siz,&q);
        deque<int>d;
        while(q--)
        {
            string s;
            int x;
            cin>>s;
            if(s=="pushLeft")
            {
                cin>>x;
                if(d.size()==siz) prf;
                else
                {
                    printf("Pushed in left: %d\n",x);
                    d.push_back(x);
                }
            }
            else if(s=="pushRight")
            {
                cin>>x;
                if(d.size()==siz) prf;
                else
                {
                    printf("Pushed in right: %d\n",x);
                    d.push_front(x);
                }
            }
            else if(s=="popLeft")
            {
                if(d.empty()) pre;
                else
                {
                    printf("Popped from left: %d\n",d.back());
                    d.pop_back();
                }
            }
            else if(s=="popRight")
            {
                if(d.empty()) pre;
                else
                {
                    printf("Popped from right: %d\n",d.front());
                    d.pop_front();
                }
            }
        }
    }
    return 0;
}
