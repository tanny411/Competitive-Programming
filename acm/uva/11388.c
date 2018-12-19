#include<stdio.h>

int main()
{

    int t,G,L;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&G,&L);

        if(L%G==0) printf("%d %d\n",G,L);
        else printf("-1\n");
    }
    return 0;
}
