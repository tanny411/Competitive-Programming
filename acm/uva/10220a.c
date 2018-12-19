#include<stdio.h>
#include<math.h>
#include<string.h>

char ara1[4000],ara2[4000];
int len,count[1002];

void fibo()
{
    count[0]=count[1]=1;
    ara1[0]=1;
    ara1[1]=0;
    int i,j,r,k,len=1;
    for(i=2;i<1001;i++)
    {
        r=0;
        for( j=0; j<len ;j++ )
        {
            r=r+ara1[j]*i;
            ara2[j]=r%10;
            r/=10;
        }
        while(r>0)
        {
            ara2[j]=r%10;
            r/=10;
            j++;
        }
        len=j;
        count[i]=0;
        for(k=0;k<len;k++)
        {
            count[i]+=ara2[k];
            ara1[k]=ara2[k];
        }
    }
}

int main()
{
    int n;
    fibo();
    while(scanf("%d",&n)==1)
    {
        printf("%d\n",count[n]);
    }
    return 0;
}
