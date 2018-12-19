#include<stdio.h>
#include<math.h>
#define maximum 1500

int ara[maximum],count[maximum],prime[maximum],ind=2;

void sieve()
{
    int n=sqrt(maximum),i,j;
    prime[0]=1;
    prime[1]=2;
    ara[0]=1;
    ara[1]=0;///for this problem 1 is prime!///
    ara[2]=0;
    count[0]=0;
    count[1]=2;
    count[2]=2;
    for(i=4;i<maximum;i+=2) ara[i]=1;///setting all multiples of two as not-prime!

    for(i=3;i<=maximum;i+=2)
    {
        count[i]=count[i-2];
        count[i-1]=count[i-2];
        if(!ara[i])
        {
            prime[ind++]=i;
            count[i]++;
            for(j=i*i;j<maximum;j+=i<<1)
            {
                ara[j]=1;
            }
        }
    }
    count[1]=1;
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,N,C,l,j,flag;
    sieve();
    while(scanf("%d %d",&N,&C)==2)
    {
        printf("%d %d:",N,C);
        if(count[N]&1)
        {
            C=(C*2)-1;
        }
        else
        {
            C*=2;
        }
        flag=1;
        if(C>=count[N])
        {
            flag=0;
        }
        if(flag)
        {
            for(j=0,i=count[N]/2-(C/2); j<C; j++,i++)
            {
                printf(" %d",prime[i]);
            }
            printf("\n\n");
        }
        else
        {
            for(i=1;i<=N;i++)
            {
                if(!ara[i]) printf(" %d",i);
            }
            printf("\n\n");
        }
    }
    return 0;
}
