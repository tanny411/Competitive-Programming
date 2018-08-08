#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        unordered_map<int,int>mp;
        int ans=0;
        while(n--)
        {
            int x;
            cin>>x;
            if(mp[x]==0) mp[x]=1;
            else ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
