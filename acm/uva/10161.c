#include<stdio.h>
#include<math.h>

int main()
{
    int n,isq,abs,ord,remain;
    double dsq;
    while(scanf("%d",&n)==1 && n!=0)
    {
        dsq=sqrt((double)n);
        isq=dsq;
        if( ( dsq-(double)isq ) ==0 )
        {
            if(isq&1)
            {
                abs=1;
                ord=isq;
            }
            else
            {
                abs=isq;
                ord=1;
            }
        }
        else
        {
            //sq=isq*isq;
            if(isq&1)
            {
                remain=n-isq*isq;
                if(remain<=(isq+1))
                {
                    abs=remain;
                    ord=isq+1;
                }
                else
                {
                    abs=isq+1;
                    ord=isq+isq-remain+2;///(isq+1)-(remain-(isq+1));
                }
            }
            else
            {
                remain=n-isq*isq;
                if(remain<=(isq+1))
                {
                    abs=isq+1;
                    ord=remain;
                }
                else
                {
                    abs=isq+isq-remain+2;///(isq+1)-(remain-(isq+1));
                    ord=isq+1;
                }
            }
        }
        printf("%d %d\n",abs,ord);
    }
    return 0;
}
