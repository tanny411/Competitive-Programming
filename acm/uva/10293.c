#include<stdio.h>
#include<string.h>
int main()
{

    char ara[100000];
    int i,count,ase,f[33],flag,first=0;
    while(scanf("%[^#]", ara)==1)
    {
        flag=0;
        getchar();
        memset(f,0,sizeof(f));
        for(i=0;ara[i];i++)
        {
            if(!flag) count=0;
            while(isalpha(ara[i]))
            {
                i++;
                count++;
            }
            if(ara[i]=='\'' || ara[i]=='-')
            {
                if(ara[i]=='-' && ara[i+1]=='\n') i++;
                //i++;
                flag=1;
            }
            else flag=0;
            if(!flag) f[count]++;
        }
        if(first) printf("\n");
        first=1;
        for(i=1;i<31;i++)
        {
            if(f[i]) printf("%d %d\n",i,f[i]);
        }
    }
    return 0;
}
