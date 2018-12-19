#include<bits/stdc++.h>
int main()
{

    int test,s,i,j,l;
    char ara[10010];
    double sq;
    scanf("%d",&test);
    getchar();
    while(test--)
    {
        gets(ara);
        l=strlen(ara);
        sq=sqrt(l);
        s=sq;
        if((sq-s)==0)
        {
            for(i=0;i<s;i++)
            {
                for(j=i;j<l;j+=s)
                {
                    printf("%c",ara[j]);
                }
            }
            printf("\n");
        }
        else printf("INVALID\n");

    }
    return 0;
}
