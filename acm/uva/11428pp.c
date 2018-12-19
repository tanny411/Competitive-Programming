#include<stdio.h>
#include<math.h>

long long ara[100];

void generate_cubes()
{
    int i;
    for(i=0;i<100;i++)
    {
        ara[i]=i*i*i;
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    generate_cubes();
    long i,n,x,y,x3,flag;
    while(scanf("%ld",&n)==1){
            if(n==0) break;
            flag=0;
            for(y=1;y<100;y++){
                x3=n+(y*y*y);
                for(i=1;i<100;i++)
                {
                    if(ara[i]==x3)
                    {
                        flag=i;
                        break;
                    }
                }
                if(flag) break;
            }
        if(y==100) printf("No solution\n");
        else printf("%ld %ld\n",i,y);
    }
    return 0;
}


