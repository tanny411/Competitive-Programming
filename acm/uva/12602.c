#include<stdio.h>
#include<string.h>

int main()
{
    int test,i,num,alp,m;
    char ara[10];
    scanf("%d",&test);
    getchar();
    while(test--)
    {
        num=alp=0;
        gets(ara);
        for(i=7,m=1;i>3;i--,m*=10)
        {
            num+=(ara[i]-'0')*m;
        }
        for(m=1,i--;i>-1;i--,m*=26)
        {
            alp+=(ara[i]-'A')*m;
        }
        num-=alp;
        if(num<0) num*=-1;
        if(num<=100) printf("nice\n");
        else printf("not nice\n");
    }
    return 0;
}
