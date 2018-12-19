#include<cstdio>
#include<string.h>

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

void str_add(char ara1[],char ara2[],char sum[])
{
    char *str1,*str2;
    int len1,len2,lens,lenb,i,s,carry;

    len1=strlen(ara1);
    len2=strlen(ara2);

    string_reverse(ara1,len1);
    string_reverse(ara2,len2);

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

    sum[++i]=0;

    string_reverse(sum,i);

    //puts(sum);
}

int string_div(char dividend[],int divisor,char Q[])
{
    int i=0,j=0,q;

    long D=dividend[0]-'0';
    while(D<divisor){

       if(dividend[++i]) D=D*10+dividend[i]-'0';
       else {Q[0]='0';Q[1]=0;return D;} ///where the divisor>dividend

    }
    while(1){
    q=D/divisor;
    if(q==0) Q[j++]='0';
    else{
    while(q>0){
        Q[j++]=q%10+'0';
        q/=10;
    }
    }
    if(dividend[++i]=='\0'){
        D=D%divisor;
        break;
    }
    D=(D%divisor)*10+(dividend[i]-'0');

    }
    Q[j]=0;
    return D;
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int frnds,items,test=1;
    char ara1[30],ara2[30],sum[100],Q[1000];
    while(scanf("%d %d",&items,&frnds)==2)
    {
        getchar();
        if(items==0 && frnds==0) break;
        gets(ara1);
        items--;
        while(items--)
        {
            gets(ara2);
            str_add(ara1,ara2,ara1); ///result_str=ara1
        }
        string_div(ara1,frnds,Q);
        printf("Bill #%d costs %s: each friend should pay %s\n\n",test++,ara1,Q);

    }
    return 0;
}
