#include <bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
using namespace std;

int main() {

    int a,x,i,y,Count;
    vector<int>v;
    while(scanf("%d",&a)==1)
    {
        y=1<<30;
        Count=0;
        v.clear();
        for(i=a+1;i<y;i++)
        {
            double ans=double((double)a*i/(double)(i-a));
            y=ans;
            double u=y;
            if(u==ans)
            {
                v.push_back(y);
                v.push_back(i);
                Count++;
            }
        }
        printf("%d\n",Count);
        for(i=0;i<v.size();i+=2)
        {
            x=v[i];
            y=v[i+1];
            printf("1/%d = 1/%d + 1/%d\n",a,x,y);
        }
    }
    return 0;
}
