#include<stdio.h>
#include<string.h>

void str_add(char ara1[],char ara2[],char sum[])
{
    char *str1,*str2,*prn;
    int len1,len2,lens,lenb,i,s,carry;

    len1=strlen(ara1);
    len2=strlen(ara2);

    ///to make always len_ara1>len_ara2

    if(len2>len1)
    {
        str1=ara2;
        str2=ara1;
        lens=len1;
        lenb=len2;
    }
    else
    {
        str2=ara2;
        str1=ara1;
        lens=len2;
        lenb=len1;
    }

    for(i=lens;i<lenb;i++)
    {
        str2[i]='0';
    }

    str2[i]=0;
    carry=0;
    for(i=0;i<lenb;i++)
    {
        s=str1[i]+str2[i]-'0'-'0'+carry;
        if(s>9) carry=1;
        else carry=0;

        sum[i]=s%10 + '0';
    }
    if(carry) sum[i++]='1';

    for(i-- ; sum[i]=='0' && i>-1 ;i--){}

    if(i<0) sum[++i]='0';

    sum[i+1]=0;

    ///to get rid of the leading zeros

    for(i=0;sum[i]=='0';i++){}

    prn=sum+i;

    puts(prn);
}

int main()
{

    int n,i;
    char num1[300],num2[300],sum[300];
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        scanf("%s %s",num1,num2);

       str_add(num1,num2,sum);

    }
    return 0;
}
