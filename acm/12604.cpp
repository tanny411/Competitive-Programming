#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int>lps;
void computeLPS(string pat,int m)
{
    lps[0]=0;
    int len=0;
    int i=1;
    while(i<m)
    {
        if(pat[len]==pat[i]) lps[i]=++len,i++;
        else if(len!=0) len=lps[len-1];
        else lps[i]=0,i++;
    }
}

bool KMPsearch(string text,int n,string pat,int m)
{
    vector<int>in;
    int i=0,j=0;
    while(i<n)
    {
        if(text[i]==pat[j]) i++,j++;
        if(j==m) in.push_back(i-j),j=lps[j-1];
        else if(i<n && text[i]!=pat[j])
        {
            if(j>0) j=lps[j-1];
            else i++;
        }
    }
    return in.size()==1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string text,pat,alpha;
        cin>>alpha>>pat>>text;
        int n=text.length(),m=pat.length(),alsiz=alpha.size();

        lps=vector<int>(m);
        vector<int>ind(1000),ans;

        for(int i=0;i<alsiz;i++) ind[alpha[i]]=i;

        computeLPS(pat,pat.size());

        if(KMPsearch(text,n,pat,m)) ans.pb(0);
        for(int i=1;i<alsiz;i++)
        {
            for(int j=0;j<m;j++)
            {
                pat[j]=alpha[(ind[pat[j]]+1)%alsiz];
            }
            if(KMPsearch(text,n,pat,m)) ans.pb(i);
        }
        if(ans.empty()) cout<<"no solution\n";
        else if(ans.size()==1) cout<<"unique: "<<ans[0]<<endl;
        else{
            cout<<"ambiguous:";
            for(int i=0;i<ans.size();i++) cout<<" "<<ans[i];
            cout<<endl;
        }
    }
    return 0;
}

