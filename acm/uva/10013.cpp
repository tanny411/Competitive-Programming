#include<stdio.h>
#include<math.h>

int main()
{

    int n,a,b,carry,num[1000000];
    long m,i,j;
    scanf("%d",&n);
    while(n--){
        scanf("%ld",&m);
        j=0;
        while(m--){
        scanf("%d %d",&a,&b);
        num[j++]=a+b;
        }
        for(i=j-1,carry=0 ; i>-1 ; i--){
            num[i]+=carry;
            if(num[i]>9) carry=1;
            else carry=0;
            num[i]=num[i]%10;
        }
        if(carry) printf("%d",carry);
        for(i=0;i<j;i++){
            printf("%d",num[i]);
        }
        printf("\n");
        if(n) printf("\n");
    }
    return 0;
}
