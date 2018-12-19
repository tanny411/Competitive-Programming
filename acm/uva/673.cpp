#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    vector<char>st;
    int t,flag,i;
    char ara[200];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        flag=1;
        gets(ara);
        for(i=0;ara[i];i++)
        {
            if(ara[i]=='(' || ara[i]=='[') st.push_back(ara[i]);
            else if(ara[i]==')')
            {
                if(st.empty() || st.back()!='(') {flag=0;break;}
                else st.pop_back();
            }
            else
            {
                if(st.empty() || st.back()!='[') {flag=0; break;}
                else st.pop_back();
            }
        }
        if(flag)
        {
            if(st.empty()) printf("Yes\n");
            else printf("No\n");
        }
        else printf("No\n");
        st.clear();
    }
    return 0;
}
