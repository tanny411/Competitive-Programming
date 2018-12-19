#include<stdio.h>
#include<ctype.h>
#include<string.h>
long long fibonacci[100];
int binary_search(long long n)
{
        int index_start=0,index_end=50,index_mid=25;
       while(index_start<=index_end){
       if(fibonacci[index_mid]==n){
       return index_mid;}
       else if(n>fibonacci[index_mid]) index_start=index_mid+1;
        else if(n<fibonacci[index_mid]) index_end=index_mid-1;
       index_mid=(index_start + index_end)/2;
       }
        if(index_start<=index_end)
        return index_mid;
        else
        return -1;
}
void fibo()
{
    int i;
    fibonacci[0]=1;
    fibonacci[1]=2;
    for(i=2;i<50;i++)
    {
        fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
    }
}
int main()
{
    fibo();
    int test,n,i,fib,x,maxx;
    long long ara[120];
    char str[120],out[120];
    scanf("%d",&test);
    while(test--)
    {
        maxx=0;
        memset(out,' ',sizeof(out));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&ara[i]);
        }
        while(getchar()!='\n');
        gets(str);
        for(i=0,fib=0;str[i] && fib<n ;i++)
        {
            if(isupper(str[i]))
            {
                x=binary_search(ara[fib]);
                out[x]=str[i];
                fib++;
                //printf("x=%d\n",x);
                if(x>maxx) maxx=x;
            }
        }
        //printf("\n %d \n",maxx);
        out[maxx+1]=0;
        puts(out);
    }
    return 0;
}
