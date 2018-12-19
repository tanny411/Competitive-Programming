#include<stdio.h>
#include<sstream>
using namespace std;
int gcd(int a,int b)
{
    if(a%b==0) return b;
    else return(gcd(b,a%b));
}
int  main()
{
    int test,i,j,maxi,c,n,ara[150];
    char str[20000];
    stringstream ss;
    scanf("%d",&test);
    getchar();
    while(test--)
    {
        n=maxi=0;
        gets(str);
        //stringstream ss(str);
        ss << str;
        while(ss>>ara[n])
        {
            n++;
        }
        ss.clear();
        ss.str("");
        //printf("%d\n",n);
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                c=gcd(ara[i],ara[j]);
                if(c>maxi) maxi=c;
            }
        }
        printf("%d\n",maxi);
    }
    return 0;
}
