#include<stdio.h>
#include<string.h>

char ara[10][10];

int aseni(int x,int y)
{
    if(ara[x][y]=='I' || ara[x][y]=='E' || ara[x][y]=='H' || ara[x][y]=='O' || ara[x][y]=='V' || ara[x][y]=='A' || ara[x][y]=='#' ) return 1;
    else return 0;
}

int main()
{
    int test,m,n,i,j;
    char ch;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&m,&n);
        getchar();
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                ara[i][j]=getchar();
            }
            getchar();
        }
        for(j=0;j<n;j++)
        {
            if(ara[m-1][j]=='@') break;
        }
        i=m-1;
        ch='@';
        while(ch!='#')
        {
            if(j<n && aseni(i,j+1))
            {
                printf("right");
                j++;
            }
            else if(j>0 && aseni(i,j-1))
            {
                printf("left");
                j--;
            }
            else if(i>0 && aseni(i-1,j))
            {
                printf("forth");
                i--;
            }
            ch=ara[i][j];
            ara[i][j]='R';
            if(ch!='#') printf(" ");
        }
        printf("\n");
    }
    return 0;
}
