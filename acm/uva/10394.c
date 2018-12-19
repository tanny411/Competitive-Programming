#include<stdio.h>
#include<math.h>
#include<string.h>
#define range 18409900
char ara[range];
int main()
{
    long long i,S,j,k,prev,cc=1,x[100100];
    ara[0]=1;
    prev=2;
    //for(i=4;i<range;i+=2) ara[i]=1;
    for(i=3;i<range;i+=2){
        if(!ara[i]){
            if(i-prev==2)
            {
                x[cc]=prev;
                cc++;
            }

            for(j=i*i,k=i+i ;j<=range; j+=k){
                ara[j]=1;
            }
            prev=i;
        }
    }
    while(scanf("%lld",&S)==1){
        printf("(%lld, %lld)\n",x[S],x[S]+2);
    }

    return 0;
}

