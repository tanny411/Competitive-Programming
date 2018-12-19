#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,t,rv[10],j,Max;
    char in[10][105],str[105],c;
    scanf("%d",&t);
    c=getchar();
    for(i=1;i<=t;i++)

    {
        Max=-1;
        for(j=0;j<10;j++){
            gets(str);
            sscanf(str,"%s %d",in[j],&rv[j]);///cant work with in c++ string! requires c_string
            if(rv[j]>Max) Max=rv[j];

        }
        printf("Case #%d:\n",i);
        for(j=0;j<10;j++){
            if(rv[j]==Max) puts(in[j]);
        }
    }
    return 0;
}

