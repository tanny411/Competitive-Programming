#include<stdio.h>
#include<math.h>
#include<string.h>

void string_reverse(char ara[])
{
    int len=strlen(ara);
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

void str_add(char a1[],char a2[],char sum[])///giving reversed arrays
{
    char *str1,*str2,ara1[1000],ara2[1000];
    int len1,len2,lens,lenb,i,s,carry;
    strcpy(ara1,a1);
    strcpy(ara2,a2);
    len1=strlen(ara1);
    len2=strlen(ara2);

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

    //for(i-- ; sum[i]=='0' && i>-1 ;i--){}

    //if(i<0) sum[++i]='0';

    sum[i+1]=0;

}

void multiply2(char ara[],char mul[])///reversed
{
    int i,carry=0,num;
    for(i=0;ara[i];i++)
    {
        num=(ara[i]-'0')*2 + carry;
        mul[i]=(num%10) + '0';
        carry=num/10;
    }
    while(carry)
    {
        mul[i++]=carry%10+'0';
        carry/=10;
    }
    mul[i]=0;
}

char ara[1001][10000],temp[10000],res[10000];

void duh()
{
    int i;
    ara[1][0]='2';ara[1][1]='\0';
    ara[2][0]='5';ara[2][1]='\0';
    ara[3][0]='3';ara[3][1]='1';ara[3][2]='\0'; ///meaning 13

    for(i=4;i<1001;i++)
    {
        str_add(ara[i-2],ara[i-3],ara[i]);
        multiply2(ara[i-1],temp);
        str_add(ara[i],temp,ara[i]);
    }
    for(i=3;i<1001;i++)
    {
    string_reverse(ara[i]);
    }
}

int main()
{
    int n;
    duh();
    while(scanf("%d",&n)==1)
    {
        printf("%s\n",ara[n]);
    }
    return 0;
}
