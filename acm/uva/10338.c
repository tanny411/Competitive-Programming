#include<stdio.h>
#include<string.h>

int main()
{
    int n,i,count[27],x,data=1;
    long long ara[21],num;
    ara[0]=1;
    ara[1]=1;
    for(n=2;n<21;n++)
    {
        ara[n]=n*ara[n-1];
    }
    memset(count,0,sizeof(count));
    char str[100];
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(str);
        for(i=0;str[i];i++)
        {
            count[str[i]-'A']++;
        }
        num=ara[i];
        for(i=0;str[i];i++)
        {
            x=str[i]-'A';
            if( count[x]>1 )
            {
                num/=ara[count[x]];
            }
            count[x]=0;
        }
        printf("Data set %d: %lld\n",data++,num);
    }

    return 0;
}
