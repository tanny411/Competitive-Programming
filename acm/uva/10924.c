#include<stdio.h>
#include<string.h>
#define max 1050
int flag[max];

void sieve()
{
    int sq=33,i,j,k;
    for(i=4;i<max;i+=2) flag[i]=1;
    for(i=3;i<sq;i+=2)
    {
        if(!flag[i])
        {
            for(j=i*i,k=i+i;j<max;j+=k)
            {
                flag[j]=1;
            }
        }
    }
}

int main()
{
    sieve();
    char ara[30];
    int i,sum;
    while(gets(ara))
    {
        sum=0;
        for(i=0;ara[i];i++)
        {
            if(isupper(ara[i]))
            {
                sum += ara[i]-38;
            }
            else
            {
                sum += ara[i]-96;
            }
        }
        if(flag[sum]) printf("It is not a prime word.\n");
        else printf("It is a prime word.\n");
    }
    return 0;
}
