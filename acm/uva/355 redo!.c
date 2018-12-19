#include<stdio.h>///1099511627775==ffffffffff
#include<string.h>
#include<ctype.h>
char fnum[100];

long long to_10_base(int basef, char num[])
{
    int valid=basef-1,i,digit;
    long long base10=0,mul;
    for(i=strlen(num)-1,mul=1  ;i>-1;  i--,mul*=basef)
    {
     if(isalpha(num[i]))  digit=toupper(num[i])-'A'+10;
     else  digit=num[i]-'0';
     if(digit>valid) return -1;
     base10+=digit*mul;
    }
    return base10;

}

void to_another_base(long long number,int baset)
{
    int digit,i=0,flag=1;
    while(number)
    {
        digit=number%baset;
        if(digit>9) fnum[i++]=digit+'A'-10;
        else fnum[i++]=digit+'0';

        number=number/baset;
        flag=0;
    }
    if(flag) fnum[i++]='0';
    fnum[i]=0;
    return;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int basef,baset,i;
    long long number;
    char num[100],garbage;
    while(scanf("%d %d",&basef,&baset)==2)
    {
        garbage=getchar();
        gets(num);
        number=to_10_base(basef,num);

        if(number!=-1){
        if(baset==10)
        printf("%s base %d = %lld base 10\n",num,basef,number,baset);
        else{
        to_another_base(number,baset);
        printf("%s base %d = ",num,basef);
        for(i=strlen(fnum)-1;i>-1;i--)
        printf("%c",fnum[i]);
        printf(" base %d\n",baset);
        }
        }
        else printf("%s is an illegal base %d number\n",num,basef);


        //printf("%lld\n\n",to_10_base(basef,num));///check-line
    }

    return 0;
}
