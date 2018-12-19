#include<stdio.h>
#include<string.h>

int num[1000004];
int main()
{
    char ara[1000004];
    int i,n,test=1,a,b,no,flag,br;
    while( gets(ara) && strlen(ara) )
    {
        no=1;
        num[0]=1;
        for(i=1;ara[i];i++)
        {
            flag=br=0;
            while(ara[i]==ara[i-1])
            {
                num[i]=no;
                i++;
                flag=1;
                if(ara[i]==0) {br=1;break;}
            }
            if(br) break;
            if(flag) i--;
            else num[i]=no+1;
            no++;
        }
        //for(i=0;ara[i];i++) printf("%d ",num[i]);
        scanf("%d",&n);
        printf("Case %d:\n",test++);
        while(n--)
        {
            scanf("%d %d",&a,&b);
            getchar();
            if(num[a]==num[b]) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
