#include<stdio.h>
#include<string.h>
#include<math.h>
//char Q[1000];
int string_div(char dividend[],int divisor)
{
    int i=0,j=0,q;
    //printf("func");
    //char Q[1000];

    long D=dividend[0]-'0';
    while(D<divisor){

        if(dividend[++i]) D=D*10+dividend[i]-'0';
        else return D;
    }
    while(1){
        //printf("in func loop");
    q=D/divisor;
  /*  while(q>0){
        Q[j++]=q%10+'0';
        q/=10;
    }*/
    if(dividend[++i]=='\0'){
        D=D%divisor;
        break;
    }
    D=(D%divisor)*10+dividend[i]-'0';

    }
   // Q[j]='\0';
    return D;
}

int main()
{
    char ara[110];
    int l;
    while(gets(ara)){
        if(strlen(ara)==1 && ara[0]=='0') break;
        if(string_div(ara,17)) printf("0\n");
        else printf("1\n");
    }
    return 0;
}

