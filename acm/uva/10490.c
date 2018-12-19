#include<stdio.h>
#include<math.h>
int main()
{

    int perfect[]={ 2,3,5,7,13,17,19,31 },notperfect[]={11,23,29},n,i,fp,fnp;
    long long x;
    while(scanf("%d",&n)==1 && n!=0)
    {
        fp=fnp=0;
        for(i=0;i<8;i++)
        {
            if(n==perfect[i]) fp=1;
        }
        if(!fp)
        {
            for(i=0;i<3;i++)
            {
                if(n==notperfect[i]) fnp=1;
            }
        }
        if(fp)
        {
            x=pow(2,n-1)*(pow(2,n)-1);
            printf("Perfect: %lld!\n",x);
        }
        else if(fnp)
        {
            printf("Given number is prime. But, NO perfect number is available.\n");
        }
        else
        {
            printf("Given number is NOT prime! NO perfect number is available.\n");
        }
    }
    return 0;
}
