#include<bits/stdc++.h>

#define ll long long

#define fs first
#define sc second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        ///You have to find the number of times p(pattern) occurs as a substring of t(text) all lower case.
        string t,p;
        cin>>t>>p;
        int m=p.length();
        ll ans=(ll)p[0];
        ll hh=(ll)t[0];
        ll baad=1;
        for(int i=0;i<m;i++)
        {
            baad*=29;
        }
        for(int i=1;i<m;i++)
        {
            ans=ans*29+(ll)p[i];
            hh=hh*29+(ll)t[i];
        }
        int cnt=0;
        if(hh==ans) cnt++;
        for(int i=m;i<t.length();i++)
        {
            hh=hh*29+(ll)t[i];
            hh-=baad*(ll)t[i-m];
            if(hh==ans) cnt++;
        }
        cout<<"Case "<<cas++<<": "<<cnt<<"\n";
    }
    return 0;
}
