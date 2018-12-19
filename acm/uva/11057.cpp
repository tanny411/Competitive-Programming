#include<stdio.h>
//#include<math.h>
#include<algorithm>
//#include<search.h>
using namespace std;
int Bin_search(int index_start,int index_end,int n,int des[])
{
    int index_mid=(index_start + index_end)/2;
       while(index_start<=index_end){
       if(des[index_mid]==n){
       return index_mid;}
       else if(n>des[index_mid]) index_start=index_mid+1;
       else if(n<des[index_mid]) index_end=index_mid-1;
       index_mid=(index_start + index_end)/2;
       }
       if(index_start>index_end)
      return -1;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n,ara[10010],cost,i,a,b,x,p;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&ara[i]);
        }
        scanf("%d",&cost);
        sort(ara,ara+n);
        p=n;
        for(i=0;i<p;i++)
        {
            //if(binary_search(ara+i+1,ara+n,cost-ara[i]))
            x=Bin_search(i+1,n-1,cost-ara[i],ara);
            if(x!=-1)
            {
                p=x;
                a=ara[i];
                b=cost-ara[i];
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",a,b);
    }
    return 0;
}
