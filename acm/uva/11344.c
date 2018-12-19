#include<stdio.h>
#include<math.h>
#include<string.h>
int div(char str[], int a)
{
    int i,mod=0,b=10%a;
    for(i=0;str[i];i++){
        mod=(mod*b + str[i]-'0')%a;
    }
    if(mod) return 1;
    else return 0;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,s,se,i,flag,rem;
    char p,ara[1010],cpy[1010];
    scanf("%d",&t);

    while(t--){
        p=getchar();
        gets(ara);
        scanf("%d",&s);
        flag=0;
        for(i=0;i<s;i++)
        {
            scanf("%d",&se);
            if(flag==1) continue;
            if(se==1) continue;
            if(div(ara,se)) flag=1;

        }
        if(flag) printf("%s - Simple.\n", ara);
        else printf("%s - Wonderful.\n", ara);
    }
    return 0;
}
