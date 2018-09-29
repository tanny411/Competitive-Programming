#include<bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;
int main()
{
    //ios_base::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        getchar();
        while(n--)
        {
            char s[150],tittle[150],auth[150],journal[150],volume[150],number[150],year[150],pages[150];
            while(1)
            {
                scanf(" %[^\n]",s);
                if(s[0]=='}') break;
                int sz=strlen(s);
                //cout<<s<<endl;
                if(s[sz-1]==',') sz-=2;
                else sz--;
                if(s[0]=='t')
                {
                    int in=0;
                    for(int i=7;i<sz;i++) tittle[in++]=s[i];
                    tittle[in]=0;
                }
                else if(s[0]=='a')
                {
                    int in=0;
                    for(int i=8;i<sz;i++)
                    {
                        if(s[i-1]=='{' || s[i-2]==',')
                        {
                            auth[in++]=s[i];
                            auth[in++]=s[i+1];
                            auth[in++]='.';
                            auth[in++]=' ';
                        }
                        else if(s[i-1]==' ' && s[i-2]!=',') {
                            auth[in++]=s[i];
                            auth[in++]=',';
                            auth[in++]=' ';
                        }
                    }
                    auth[in-2]=0;
                    //printf("%sPOLO\n",auth);
                }
                else if(s[0]=='j')
                {
                    int in=0;
                    for(int i=9;i<sz;i++) journal[in++]=s[i];
                    journal[in]=0;
                }
                else if(s[0]=='v')
                {
                    int in=0;
                    for(int i=8;i<sz;i++) volume[in++]=s[i];
                    volume[in]=0;
                }
                else if(s[0]=='n')
                {
                    int in=0;
                    for(int i=8;i<sz;i++) number[in++]=s[i];
                    number[in]=0;
                }
                else if(s[0]=='p' && s[1]=='a')
                {
                    int in=0;
                    for(int i=7;i<sz;i++) pages[in++]=s[i];
                    pages[in]=0;
                }
                else if(s[0]=='y')
                {
                    int in=0;
                    for(int i=6;i<sz;i++) year[in++]=s[i];
                    year[in]=0;
                }
            }
            printf("%s. %s. %s. %s;%s(%s):%s.\n",auth,tittle,journal,year,volume,number,pages);
            //s=auth+". "+tittle+". "+journal+". "+year+";"+volume+"("+number+"):"+pages+".\n";
        }
    }
    return 0;
}
/**
@article{
title={Testing},
author={Ahmed Salem},
journal={Planta},
volume={10},
number={7},
pages={20-30},
year={2016},
publisher={Springer}
}
@article{
pages={20-30},
year={2016},
publisher={Springer},
title={Testing},
author={Ahmed Salem},
journal={Planta},
volume={10},
number={7}
}
@article{
volume={10},
number={7},
pages={20-30},
year={2016},
publisher={Springer},
title={Testing},
author={Ahmed Salem},
journal={Planta}
}
*/

