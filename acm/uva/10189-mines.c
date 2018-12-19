
#include<stdio.h>
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int field=1,m,n,i,j,start=0;
    char in[110][110],out[110][110];
    while(scanf("%d %d",&m,&n)==2)
    {

        getchar();
        if(m==0 && n==0) break;
        if(start) {printf("\n");}
        start=1;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                out[i][j]='0';
            }
        }

        for(i=0;i<m;i++)
        {
            gets(in[i]);
            for(j=0;j<n;j++)
            {
                if(in[i][j]=='*')
                {
                    //out[i][j]='*';
                    out[i][j+1]++;
                    out[i][j-1]++;
                    out[i-1][j-1]++;
                    out[i-1][j]++;
                    out[i-1][j+1]++;
                    out[i+1][j-1]++;
                    out[i+1][j]++;
                    out[i+1][j+1]++;

                }
            }
        }
        printf("Field #%d:\n",field++);
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(in[i][j]=='*')
                    out[i][j]='*';
            }
            out[i][n]=0;
            puts(out[i]);
        }

    }
    return 0;
}
