#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int n,i,j,p,q,shit,flag[3000],x;
    while(scanf("%d",&n)==1)
    {
        x=n;
        memset(flag,0,sizeof(flag));
        shit=0;
        scanf("%d",&p);

        for(n--;n;n--)
        {
            scanf("%d",&q);
            if(shit) continue;
            j=abs(p-q);
            if(j>=x) shit=1;
            else if(flag[j])
            {
                shit=1;
            }
            else
            {
                flag[j]=1;
            }
            p=q;
        }

        if(shit) printf("Not jolly\n");
        else printf("Jolly\n");
    }
  return 0;
}

