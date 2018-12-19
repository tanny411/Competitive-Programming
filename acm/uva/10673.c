#include<stdio.h>
#include<math.h>

int main()
{
    int t,a,b,p,q,x,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&x,&k);
        //printf("x %d k %d\n",x,k);
        b=ceil((double)x/k);
        a=floor((double)x/k);
        //printf("floor %d ceil %d\n",b,a);
        for(p=0;;p++)
        {
            //printf(".");
            if((x-(a*p))%b==0)
            {
                //printf("lala\n");
                q=(x-(a*p))/b;
                break;
            }
        }
        printf("%d %d\n",p,q);
    }
    return 0;
}
