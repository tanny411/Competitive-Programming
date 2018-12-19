#include<cstdio>
#include<string.h>

int main()
{
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int t,i,j,ara[150],pos;
    char brainfuck[100000];
    scanf("%d",&t);
    getchar();
    for(i=1;i<=t;i++)
    {
        gets(brainfuck);
        pos=0;
        memset(ara,0,sizeof(ara));
        for(j=0;brainfuck[j];j++)
        {
                 if(brainfuck[j]=='>') { pos++; if(pos==100) pos=0 ; }///because 0-99 is 100 bytes!
            else if(brainfuck[j]=='<') { pos--; if(pos==-1) pos=99; }
            else if(brainfuck[j]=='+') { ara[pos]++; if(ara[pos]==256) ara[pos]=0; }
            else if(brainfuck[j]=='-') { ara[pos]--; if(ara[pos]==-1) ara[pos]=255; }
        }
        printf("Case %d:",i);
        for(j=0;j<100;j++)
        {
            printf(" %02X",ara[j]);
        }
        printf("\n");

    }
    return 0;
}
