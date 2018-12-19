#include <bits/stdc++.h>
using namespace std;

int ara[15];
int flag[15],n,s;
map<string,int>m;
vector<int>v;
string num;
char str[5];

void func(int sum,int in)
{
    if(sum==s)
    {
        num.clear();
        stringstream ss;
        for(int i=0;i<v.size();i++)
        {
            //sscanf(v[i] , "%s" , str);
            ss.clear();
            ss<<v[i];
            ss>>str;
            num+=str;
            num+=' ';
        }
        if(!m[num])
        {
            m[num]=1;
            //cout<<num<<endl;
            cout<<v[0];
            for(int i=1;i<v.size();i++)
            {
                cout << '+' << v[i] ;
            }
            cout<<endl;
        }
    }

    for(int i=in;i<n;i++)
    {
        if(sum+ara[i]<=s)
        {
            v.push_back(ara[i]);
            func(sum+ara[i],i+1);
            v.pop_back();
        }
    }
}

int main() {

        while(scanf("%d %d",&s,&n)==2 )
        {
            if(n==0 && s==0) return 0;
            m.clear();
            v.clear();
            for(int i=0;i<n;i++)
            {
                scanf("%d",&ara[i]);
            }
            printf("Sums of %d:\n",s);
            func(0,0);
            if(m.empty()) printf("NONE\n");
        }

    return 0;
}
