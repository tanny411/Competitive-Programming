#include<stdio.h>
#include<string.h>
int main()
{
    char right[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./",ara[1000];
    int i,j;
    while(gets(ara))
    {
        for(i=0;ara[i];i++)
        {
            if(ara[i]!=' ')
            {
            for(j=0;;j++)
            {
                if(right[j]==ara[i]) break;
            }
            ara[i]=right[j-1];
            }
        }
        printf("%s\n",ara);
    }
    return 0;
}
