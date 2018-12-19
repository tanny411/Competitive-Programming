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

int ara[10][20],in8,in6,in4,in2;

void func8()
{
    for(int i=0;i<100000000;i++)
    {
        int x=(i%10000);
        int y=i/10000;
        x=(x+y);
        x*=x;
        if(x==i) ara[8][in8++]=i;
    }
}

void func6()
{
    for(int i=0;i<1000000;i++)
    {
        int x=(i%1000);
        int y=i/1000;
        x=(x+y);
        x*=x;
        if(x==i) ara[6][in6++]=i;
    }
}

void func4()
{
    for(int i=0;i<10000;i++)
    {
        int x=(i%100);
        int y=i/100;
        x=(x+y);
        x*=x;
        if(x==i) ara[4][in4++]=i;
    }
}


void func2()
{
    for(int i=0;i<100;i++)
    {
        int x=(i%10);
        int y=i/10;
        x=(x+y);
        x*=x;
        if(x==i) ara[2][in2++]=i;
    }
}

int main() {

    func2();
    func4();
    func6();
    func8();
    int x;
    //printf("done\n");
    while(scanf("%d",&x)==1)
    {
        if(x==2)
        {
            for(int i=0;i<in2;i++) printf("%02d\n",ara[2][i]);
        }
        else if(x==4)
        {
            for(int i=0;i<in4;i++) printf("%04d\n",ara[4][i]);
        }
        else if(x==6)
        {
            for(int i=0;i<in6;i++) printf("%06d\n",ara[6][i]);
        }
        else if(x==8)
        {
            for(int i=0;i<in8;i++) printf("%08d\n",ara[8][i]);
        }
    }
    return 0;
}
