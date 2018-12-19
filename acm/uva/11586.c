#include<stdio.h>

int main()
{
    int test,i,M,F;
    char ara[1000];
    scanf("%d",&test);
    getchar();
    while(test--)
    {
        M=F=0;
        gets(ara);
        for(i=0;ara[i];i++)
        {
            if(ara[i]=='M') M++;
            else if(ara[i]=='F') F++;
        }
        if(M==F && M!=1) printf("LOOP\n");
        else printf("NO LOOP\n");
    }
    return 0;
}
