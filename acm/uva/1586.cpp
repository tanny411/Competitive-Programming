#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<map>
using namespace std;
int main()
{
    map<char,double>val;
    val['C']=12.01;val['H']=1.008;val['O']=16.00;val['N']=14.01;
    int test,i,j,k,m,num,p;
    char ara[100];
    double mass;
    scanf("%d",&test);
    getchar();
    while(test--)
    {
        gets(ara);
        mass=0;
        for(i=0;ara[i];i++)
        {
            if(isdigit(ara[i])) continue;
            p=i+1;
            while(isdigit(ara[p])) p++;
            p--;
            if(p==i) num=1;
            else { num=0;m=1;
            while(p!=i)
            {
                num+=(ara[p--]-'0')*m;
                m*=10;
            }
            }
            mass+=val[ara[i]]*(double)num;
        }
        printf("%.3lf\n",mass);
    }
    return 0;
}
