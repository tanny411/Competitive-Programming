#include<bits/stdc++.h>///first ever DP!

long long ara[1000];

long long male(int n)
{
    if(ara[n]==-1){
        ara[n]=male(n-1)+male(n-2)+1;
    }
    return ara[n];
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    memset(ara,-1,sizeof(ara));
    ara[0]=0;
    ara[1]=1;
    int N;
    while(scanf("%d",&N)==1 && N!=-1){
    printf("%lld %lld\n",male(N),male(N)+male(N-1)+1);
   // printf("    vector size=%d\n",dpara.size());
    }
    return 0;
}
