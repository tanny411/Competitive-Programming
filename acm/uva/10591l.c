#include<stdio.h>
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,i;
    long n,x,sum,r;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%ld",&n);
        x=n;

        do{
        sum=0;
        do{//summing digit squares
            sum+=(x%10)*(x%10);
            x/=10;
        }
        while(x>0);
        x=sum;
        }
        while(x>9);

        if(x==1) printf("Case #%d: %ld is a Happy number.\n",i,n);
        else printf("Case #%d: %ld is an Unhappy number.\n",i,n);

    }
    return 0;
}
