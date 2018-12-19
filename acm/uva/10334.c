#include<stdio.h>
#include<string.h>

int str_add(char ara1[],char ara2[],char sum[])
{
    char *str1,*str2;
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

    sum[i]=0;
    ara1[len1]=0;
    ara2[len2]=0;
    return i;

}

void string_reverse(char ara[],int len)
{
    int i,l=len/2;
    len--;
    char c;
    for(i=0;i<l;i++)
    {
        c=ara[i];
        ara[i]=ara[len-i];
        ara[len-i]=c;
    }

}

char ara[1005][1100];
int lengths[5500];

void fuck()
{
    int i;
    char *str;
    for(i=2;i<1001;i++)
    {
        lengths[i]=str_add(ara[i-1],ara[i-2],ara[i]);
    }
    for(i=2;i<1001;i++)
    {
        str=ara[i];
        string_reverse(ara[i],lengths[i]);
    }

}
int main()
{
    ara[0][0]='1';ara[0][1]=0;
    ara[1][0]='2';ara[1][1]=0;
    fuck();
    int n;
    while(scanf("%d",&n)==1){
        printf("%s\n",ara[n]);
    }
    return 0;
}
