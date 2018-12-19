#include<stdio.h>

int main()
{
    int testcase,len,garb;
    char ara[10];
    scanf("%d",&testcase);
    garb=getchar();
    while(testcase--)
    {
        gets(ara);
        if(strlen(ara)==5)
        {
            printf("3\n");
        }
        else
        {
            if( (ara[0]=='o' && ara[1]=='n') || (ara[2]=='e' && ara[1]=='n') || (ara[0]=='o' && ara[2]=='e') )
                printf("1\n");
            else //if ((ara[0]=='t' && ara[1]=='w') || (ara[2]=='o' && ara[1]=='w') || (ara[0]=='t' && ara[2]=='o') )
                printf("2\n");
        }
    }
    return 0;
}
