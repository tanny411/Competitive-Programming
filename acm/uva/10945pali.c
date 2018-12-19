#include<stdio.h>
#include<string.h>

int main()
{
    char done[]="DONE",ara[100000],check[100000];
    int i,j,k;
    while(1)
    {
        gets(ara);
        if(strcmp(ara,done)==0) break;
        if(ara[0]==0) { printf("You won't be eaten!\n"); continue; }
        for(i=0,j=0;ara[i];i++)
        {
            if(isalpha(ara[i]))
            {
                check[j++]=toupper(ara[i]);
            }
        }
        k=j-1;
        j/=2;
        for(i=0; i<j ;i++,k--)
        {
            if(check[i]!=check[k])
            {
                break;
            }
        }
        if(i==j) printf("You won't be eaten!\n");
        else printf("Uh oh..\n");
    }
    return 0;
}
