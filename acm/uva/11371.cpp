#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

bool comp(char a,char b)
{
    return a>b;
}

int main()
{
    char ara[20];
    int l,i;
    long num1,num2,num;

    while(gets(ara))
    {
        l=strlen(ara);
        sort(ara,ara+l,comp);///the big number
        num1=atol(ara);
        sort(ara,ara+l);
        if(ara[0]=='0')
        {
            i=1;
            while(ara[i]=='0') i++;
            swap(ara[0],ara[i]);
        }
        num2=atol(ara);
        num=num1-num2;
        printf("%ld - %ld = %ld = 9 * %ld\n",num1,num2,num,num/9);
    }
    return 0;
}
