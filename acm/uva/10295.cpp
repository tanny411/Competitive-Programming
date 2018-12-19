#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    int n,m,x,sum;
    map<string,int>word;
    string w;
    while(scanf("%d %d",&n,&m)==2)
    {
        word.clear();
        while(n--)
        {
            cin >> w >> x;
            word[w]=x;
        }
        while(m--)
        {
            sum=0;
            while(1)
            {
                cin>>w;
                if(w==".") break;
                sum+=word[w];
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
