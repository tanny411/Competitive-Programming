#include<stdio.h>

int main()
{//   freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int t,i,n,p,q,j,eggW[32],W,count,skip;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        W=0;
        skip=0;
        count=0;
        scanf("%d %d %d",&n,&p,&q);
        for(j=0;j<n;j++)
        {
            scanf("%d",&eggW[j]);
            if(skip) continue;
            W+=eggW[j];
            if(W>q || j+1>p){
                count=j;
                skip=1;
            }
        }
        if(!skip) count=n;
        printf("Case %d: ",i);
        printf("%d\n",count);
    }
    return 0;
}
