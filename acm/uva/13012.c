#include<stdio.h>

int main()
{
    int a,b,count,i;
    while(scanf("%d",&a)==1){
        count=0;
        for(i=0;i<5;i++){
            scanf("%d",&b);
            if(b==a) count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
