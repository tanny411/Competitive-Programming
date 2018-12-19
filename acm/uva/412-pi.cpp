#include<cstdio>
#include<stdio.h>
#include<math.h>

int gcd(int x,int y)
{
    if(x==0) return y;
    if(y==0) return x;
    return gcd(y , x%y);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,i,ara[55],j;
    double TotalPairs,Gpair;
    while(scanf("%d",&t)==1){
        if(t==0) break;
        TotalPairs=0;
        Gpair=0;
        for(i=0;i<t;i++){
        scanf("%d",&ara[i]);
        }
        for(i=0;i<t-1;i++){
            for(j=i+1;j<t;j++){
                TotalPairs++;
                //int G=gcd(ara[i],ara[j]);
                //printf("gcd=%d\n",G);
                if(gcd(ara[i],ara[j])==1) Gpair++;

            }
        }
        if(Gpair==0) printf("No estimate for this data set.\n");
        else{
            printf("%.6lf\n",sqrt(6*TotalPairs/Gpair));
        }
    }
    return 0;
}
