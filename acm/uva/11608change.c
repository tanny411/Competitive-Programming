#include<cstdio>
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,i,created[15],used[15],t=1;///n=no.of problems at the beginning of the year.
    while(scanf("%d",&n)==1)
    {
        if(n<0) return 0;
        printf("Case %d:\n",t++);
        created[0]=n;
        for(i=1;i<13;i++){
            scanf("%d",&created[i]);
        }

        for(i=0;i<12;i++){
        scanf("%d",&used[i]);
        }

        for(i=0;i<12;i++){
            //printf("n=%d",n);
            if(created[i]>=used[i]){
                printf("No problem! :D\n");
                created[i+1]=created[i+1] + created[i] - used[i];
            }
            else{
                printf("No problem. :(\n");
                created[i+1]+=created[i];
            }
        }
    }
    return 0;
}
