#include<stdio.h>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    stack<int>temp;
    queue<int>out;
    int n,i,j,N,a,in;
    while(scanf("%d",&N)==1 && N)
    {
        while(scanf("%d",&a) && a)
        {
            while(!out.empty()) out.pop();
            while(!temp.empty()) temp.pop();

            out.push(a);
            n=N-1;
            while(n--)
            {
            scanf("%d",&a);
            out.push(a);
            }
            in=1;
            while(!out.empty() && in<=N)
            {
                if(in==out.front()) { out.pop(); in++;}
                else if(!temp.empty() && temp.top()==out.front()) { out.pop(); temp.pop();}
                else { temp.push(in); in++;}
            }
            while(!out.empty() && !temp.empty())
            {
                if (temp.top()==out.front()) { out.pop(); temp.pop(); }
                else break;
            }
            if(out.empty()) printf("Yes\n");
            else printf("No\n");
        }
        printf("\n");
    }
    return 0;
}
