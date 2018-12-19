
#include<stdio.h>
int main()
{
    int test,i,j,k,len,sum,flag,count;
    char ara[1500];
    scanf("%d",&test);
    getchar();
    for(k=1;k<=test;k++)
    {
        sum=count=0;
        gets(ara);
        for(j=0;ara[j];j++)
        {
            ara[j]-='0';
            sum+=ara[j];
        }
        len=j;
        flag=1;
        while(flag)
        {
        flag=0;
        for(i=0;i<j;i++)
        {
            if(ara[i]!=100)
            {
                if((sum-ara[i])%3==0)
                {
                    sum-=ara[i];
                    count++;
                    ara[i]=100;
                    flag=1;
                    break;
                }
            }
        }
        }
        if(count&1) printf("Case %d: S\n",k);
        else printf("Case %d: T\n",k);
    }
    return 0;
}
