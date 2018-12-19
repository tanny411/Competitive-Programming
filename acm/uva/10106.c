#include<stdio.h>
#include<string.h>

char res[1000];

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

void strprod(char n1[],char n2[])
{
    char ad[1000];
    memset(res,0,sizeof(res));
    int l1=strlen(n1),l2=strlen(n2),i,j,ind,num,carry,shift,end1,end2;
    end1=end2=0;
    while(end1<l1 && n1[end1]=='0')
    {
        end1++;
    }
    while(end2<l2 && n2[end2]=='0')
    {
        end2++;
    }
    if(end1==l1 || end2==l2) {res[0]='0';res[1]=0; return;}
    for(i=l1-1,shift=0;i>=end1;i--,shift++)
    {
        ind=j=shift,carry=0;
        while(j--) ad[j]=0;
        for(j=l2-1;j>=end2;j--)
        {
            num=carry+((n1[i]-'0')*(n2[j]-'0'));
            ad[ind++]=num%10;
            carry=num/10;
        }
        while(carry)
        {
            ad[ind++]=carry%10;
            carry/=10;
        }
        carry=0;
        for(j=0;j<ind;j++)
        {
            num=res[j]+ad[j]+carry;
            res[j]=num%10;
            carry=num/10;
        }
        while(carry)
        {
            res[j++]=carry%10;
            carry/=10;
        }
    }
    for(i=0;i<j;i++) res[i]+='0';
    res[j]=0;
    string_reverse(res,j);
    //strrev(res);
}

int main()
{
    char n1[1000],n2[1000];
    while(gets(n1))
    {
        gets(n2);
        strprod(n1,n2);
        puts(res);
    }
    return 0;
}
