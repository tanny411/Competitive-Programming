#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,j,n,what,flag;
    char res;
    scanf("%d",&t);
    getchar();
    for(i=1;i<=t;i++)
    {
        what=0;
        flag=0;
        scanf("%d",&n);
        getchar();
        for(j=0;j<n;j++)
        {
            res=getchar();
            getchar();
            if(flag) continue;
            if(res=='W') what=0;
            if(res!='W') what++;
            if(what==3) {flag=1; what=j;}
        }
        if(flag) printf("Case %d: %d\n",i,what+1);///Cuz j had started from 0
        else printf("Case %d: Yay! Mighty Rafa persists!\n",i);
    }
    return 0;
}
