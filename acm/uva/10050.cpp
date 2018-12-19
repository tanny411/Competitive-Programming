#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>

int main()
{
    int test,i,n,ara[150],j,flag[3655],N,sum;
    scanf("%d",&test);
    while(test--)
    {
        memset(flag,0,sizeof(flag));
        scanf("%d %d",&N,&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&ara[i]);
        }
        //std::sort(ara,ara+n);
        for(i=0;i<n;i++)
        {
            //if(ara[i]==0) continue;
            for(j=ara[i];j<=N;j+=ara[i])
            {
                flag[j]=1;
            }
        }
        for(i=6;i<=N;i+=7)
        {
            flag[i]=flag[i+1]=0;
        }
        sum=0;
        for(i=1;i<=N;i++)
        {
            sum+=flag[i];
        }
        printf("%d\n",sum);
    }
    return 0;
}
