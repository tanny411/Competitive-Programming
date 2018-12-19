#include<stdio.h>
int main()
{
    int s,a,i,j,flag;
    scanf("%d",&s);
    for(i=1;i<=s;i++){
        flag=1;
        printf("Set #%d: ",i);
        for(j=0;j<13;j++){
            scanf("%d",&a);
            if(flag==0) continue;
            if(a==0) {flag=0;}
        }
    if(flag) printf("Yes\n");
    else printf("No\n");
    }
    return 0;
}
