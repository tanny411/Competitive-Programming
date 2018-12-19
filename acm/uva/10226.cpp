#include<cstdio>
#include<map>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{

    int t,total,num,i;
    char str[30];
    map <string,int> ara;
    string name[10010];
    map <string,bool> flag;
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--)
    {
    total=0;
    num=0;
    while(gets(str) && str[0])
    {
        if(!flag[str]) {name[num++]=str; flag[str]=true;}
        ara[str]++;
        total++;

    }

    sort(name,name+num);

    for(i=0;i<num;i++)
    {
        cout << name[i];
        printf(" %.4lf\n",((ara[name[i]])/(double)total)*100);
        ara[name[i]]=0;
        flag[name[i]]=false;
    }
    if(t)printf("\n");
    }
    return 0;
}
