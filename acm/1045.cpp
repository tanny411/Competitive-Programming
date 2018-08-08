#include<bits/stdc++.h>

///

using namespace std;
double lg[1000009];
int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    lg[1]=0;
    for(int i=2;i<1000003;i++){
        lg[i]=lg[i-1]+log2(i);
    }
    //cout<<"aysha\n";
    int t;
    scanf("%d",&t);
    int test=1;
    while(t--){
        int n,base;
        scanf("%d%d",&n,&base);
        printf("Case %d: ",test++);
        //cout<<"Case "<<test++<<": ";
        if(n<=1) printf("1\n"); ///0!=1!=1
        else printf("%d\n",(int)floor(lg[n]/log2(base))+1);
    }
    return 0;
}

