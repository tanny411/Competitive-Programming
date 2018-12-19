#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int x1,x2,y1,y2,a,o;
    while(scanf("%d %d %d %d",&x1,&y1,&x2,&y2)==4){
        if(x1==0 && x2==0 && y1==0 && y2==0) break;
        a=abs(x1-x2);
        o=abs(y1-y2);
        if(a==o){
            if(a) printf("1\n");
            else printf("0\n");
        }
        else if(a==0 || o==0){
            printf("1\n");
        }
        else printf("2\n");
    }
    return 0;
}
