#include<stdio.h>
#include<string.h>

long degree;
///RE
void go_ahead(long num)
{
    if((num/10)==0) return;
    degree++;
    long sum=0;
    while(num>0)
    {
        sum+=num%10;
        num/=10;
    }
    go_ahead(sum);
}

int main()
{
    char ara[2000];
    long len,num,i;
    while(1)
    {
        gets(ara);
        len=strlen(ara);
        if(len==1 && ara[0]=='0') break;
        num=0;
        degree=0;
        for(i=0;i<len;i++)
        {
            num+= ara[i]-'0' ;
        }
        //printf("%d\n",num);
        if(num>8 && num%9==0)
        {
            degree++;
            go_ahead(num);
            printf("%s is a multiple of 9 and has 9-degree %ld.\n",ara,degree);
        }
        else printf("%s is not a multiple of 9.\n",ara);
    }
    return 0;
}
