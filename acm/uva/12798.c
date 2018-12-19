#include<stdio.h>
int main()
{
    int n,m,goals,i,j,oops,player;
    while(scanf("%d %d",&n,&m)==2)
    {
    player=0;
    for(i=0;i<n;i++)
    {
        oops=0;
        for(j=0;j<m;j++)
        {
            scanf("%d",&goals);
            if(oops) continue;
            if(goals==0) oops=1;
        }
        if(!oops) player++;
    }
    printf("%d\n",player);
    }
    return 0;
}
