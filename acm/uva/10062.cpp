#include<stdio.h>
#include<string.h>
#include<iostream>
#include<ctype.h>
//using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    // printf("abclop\rdef\nab");
    //cout << toascii('\n') <<endl;
    char str[1010];
    int i,j,minindex,fq[98],Min,flag=0;;
    while(gets(str)){
        if(flag) printf("\n");
        flag=1;
        memset(fq,0,sizeof(fq));
        for(i=0;str[i];i++){
            fq[str[i]-32]++;
        }
        for(j=0;j<98;j++){
        Min=1100;
        for(i=97;i>-1;i--){
            if(fq[i]<Min){
                Min=fq[i];
                minindex=i;
            }
        }
        if(fq[minindex]) printf("%d %d\n",minindex+32,fq[minindex]);
        fq[minindex]=1100;
        }
    }


    return 0;
}
