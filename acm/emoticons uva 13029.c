#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int up=0,down=0,ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='^') {
                if(min(up,down)>0){
                    up--;
                    down--;
                    ans++;
                }
                else up++;
            }
            else if(up>=down+1) down++;
        }
        cout<<"Case "<<test++<<": "<<ans<<endl;
    }
    return 0;
}
