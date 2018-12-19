///tell me the frequencies,kenneth
#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    char str[100000];
    int i,fq[59],Max,maxindex,j,flag;
    string P;
    while(gets(str)){
        memset(fq,0,sizeof(fq));
        for(i=0;str[i];i++){
            if(isalpha(str[i])){
                fq[str[i]-65]++;
            }
        }
        Max=-1;
        for(i=0;i<59;i++){
            if(fq[i]>Max){
                Max=fq[i];
                maxindex=i;
            }
        }
        P=char(maxindex+65);
        fq[maxindex]=-1;

        for(i=maxindex+1;i<58;i++){
        if(fq[i]==Max){
                P+=char(i+65);
            }
        }
        cout << P << " " << Max << endl;

    }
    return 0;
}
