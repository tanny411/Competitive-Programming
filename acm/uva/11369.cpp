#include<cstdio>
#include<algorithm>

int cmp(int a, int b)
{
    return a>b;
}

int main()
{
    int testcase,n,ara[30000],i,discount;
    scanf("%d",&testcase);
    while(testcase--)
    {
        discount=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&ara[i]);
        }
        std::sort(ara,ara+n,cmp);
//        for(i=0;i<n;i++)
//        {
//            printf("%d ",ara[i]);
//        }
        for(i=2;i<n;i+=3)
        {
            discount+=ara[i];
        }
        printf("%d\n",discount);
    }
    return 0;
}
