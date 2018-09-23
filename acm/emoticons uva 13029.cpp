#include<bits/stdc++.h>
using namespace std;
///wa code
int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int up=0,down=0,ans=0;
        vector<int>upcum(s.length()),downcum(s.length());
        for(int i=0;i<s.length();i++)
        {
            upcum[i]=up;
            downcum[i]=down;
            if(s[i]=='^') up++;
            else if(up>=down+1) down++;
        }
        up=0;down=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            downcum[i]-=down;
            upcum[i]-=up;
            if(s[i]=='^')
            {
                up=max(up-1,0);
                if(min(downcum[i],upcum[i])>0) ans++,up++,down++;
            } else down=max(down-1,0);;
        }
        for(int i=0;i<s.length();i++) cout<<" "<<upcum[i]; cout<<endl;
        for(int i=0;i<s.length();i++) cout<<" "<<downcum[i]; cout<<endl;

        cout<<"Case "<<test++<<": "<<ans<<endl;
    }
    return 0;
}

/**
2

^_^_^^^_^

^_^_____^^^^^^^

ans: 3,2
*/
