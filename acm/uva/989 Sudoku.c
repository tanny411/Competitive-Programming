#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

int board[9][9],A,B;



int find_unassigned(int i,int j,int n)
{
    int loop1,loop2,flag=0;
    for(loop1=i;loop1<n;loop1++){
        if(flag) j=0;
        for(loop2=j;loop2<n;loop2++){
        flag=1;
        if(board[loop1][loop2]==0){
            A=loop1,B=loop2;
            return 1;
            }
        }
    }
    return 0;
}

int place(int value,int row,int column,int n)
{
    int loop,loop2,sq,f,m;
    for(loop=0;loop<n;loop++){
        if(board[row][loop]==value || board[loop][column]==value) return 0;
    }
    sq=sqrt(n);
    for(loop=row-row%sq,f=0; f<sq ;f++,loop++){
        for(loop2=column-column%sq,m=0; m<sq ;m++,loop2++){
            if(board[loop][loop2]==value) return 0;
        }
    }
    return 1;
}

int solvesudoku(int i,int j,int n)
{

    int row,col,value;
       if(find_unassigned(i,j,n)){
            row=A,col=B;
            for(value=1;value<=n;value++){

                if(place(value,row,col,n)){

                    board[row][col]=value;
                    if(solvesudoku(row,col,n)) return 1;
                    board[row][col]=0;///>>I thought this line isnt important but its REALLY important.
                }
            }

       }
       else return 1;
    return 0;
}

void printgrid(int n)
{
   // printf("\n\n");
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d",board[i][j]);
            if(j!=n-1) printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int nsq,n,i,j,flag=0;
    while(scanf("%d",&n)==1){
        if(flag) printf("\n");
        flag=1;
        nsq=n*n;
        for(i=0;i<nsq;i++){
            for(j=0;j<nsq;j++){
                scanf("%d",&board[i][j]);
            }
        }
        if(solvesudoku(0,0,nsq))
         printgrid(nsq);
        else printf("NO SOLUTION\n");
    }
    return 0;
}



