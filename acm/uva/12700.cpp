#include<cstdio>

int main()
{
    int t,n,i,j,B,W,T,p;
    char ara[20];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        B=T=W=0;
        scanf("%d",&n);
        getchar();
        gets(ara);
        p=n;
        for(j=0;j<p;j++)
        {
            if(ara[j]=='B') B++;
            else if(ara[j]=='W') W++;
            else if(ara[j]=='T') T++;
            else if(ara[j]=='A') n--;
        }
        if(n==0) printf("Case %d: ABANDONED\n",i);
        else if(B==W) printf("Case %d: DRAW %d %d\n",i,B,T);
        else if(W==n) printf("Case %d: WHITEWASH\n",i);
        else if(B==n) printf("Case %d: BANGLAWASH\n",i);
        else if(B>W) printf("Case %d: BANGLADESH %d - %d\n",i,B,W);
        else printf("Case %d: WWW %d - %d\n",i,W,B);
    }
    return 0;
}
