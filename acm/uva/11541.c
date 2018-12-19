#include<stdio.h>
#include<string.h>

int main()
{
    int test,i,j,k,num,p,m;
    char ara[300];
    scanf("%d",&test);
    getchar();
    for(i=1;i<=test;i++)
    {
        gets(ara);
        printf("Case %d: ",i);
        for(j=0;ara[j];j++)
        {
            if(isdigit(ara[j])) continue;
            p=j+1;
            while(isdigit(ara[p])) p++;
            p--;
            m=1;num=0;
            while(p!=j)
            {
                num+=(ara[p--]-'0')*m;
                m*=10;
            }

            for(k=0;k<num;k++)
            {
                printf("%c",ara[j]);
            }
            /*
            3
A2B4D1A2
A12
A1B1C1D1
            */
        }
        printf("\n");
    }
    return 0;
}
