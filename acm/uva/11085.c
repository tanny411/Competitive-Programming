#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define column 11
int givenpos[column];
int move[column];
int min;

int ispossible(int x,int y)
{
    int i;
    for(i=1;i<y;i++)
    {
        if(move[i]==x || (abs(move[i]-x)==abs(i-y)) ) return 0;
    }
    return 1;
}

int queen(int col)
{   int i,sum=0,k,c;
    for(i=1;i<9;i++)
    {
        if(ispossible(i,col))
        {
            move[col]=i;
            if(col==8)
            {
            for(i=1;i<9;i++)
            {
                c=move[i]-givenpos[i];
                if(c!=0) sum++;
            }
            if(min>sum) min=sum;
            }
            else
            queen(col+1);
        }
    }
}

int main()
{
    int i,test=1;
    while(scanf("%d%d%d%d%d%d%d%d",&givenpos[1],&givenpos[2],&givenpos[3],&givenpos[4],&givenpos[5],&givenpos[6],&givenpos[7],&givenpos[8])==8)
    {
        min=100;
        queen(1);
        printf("Case %d: %d\n",test++,min);
    }
    return 0;
}
