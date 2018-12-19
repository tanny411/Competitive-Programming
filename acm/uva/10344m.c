#include<stdio.h>
///globals
int ara[5],taken[5],flag;

void sumitup(int numbers, int sum)
{
    if(numbers==5 && sum==23){flag=1; return;}
    else{
    int i;
    for(i=0;i<5;i++)
    {
        if(!taken[i])
        {
            taken[i]=1;
            sumitup(numbers+1,sum+ara[i]);
            sumitup(numbers+1,sum-ara[i]);
            sumitup(numbers+1,sum*ara[i]);
            taken[i]=0;
        }
    }
  }
}

int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(1)
    {
        int loop;
        for(loop=0;loop<5;loop++)
        {
            scanf("%d",&ara[loop]);
        }
        for(loop=0;loop<5;loop++)
        {
            if(ara[loop]) break;
        }
        if(loop==5) break;
        flag=0;

        for(loop=0;loop<5;loop++){
        if(flag) break;
        taken[loop]=1;
        (sumitup(1,ara[loop]));
        taken[loop]=0;
        }
        if(flag)printf("Possible\n");
        else printf("Impossible\n");
    }
    return 0;
}
