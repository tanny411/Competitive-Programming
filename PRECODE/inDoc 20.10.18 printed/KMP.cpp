#include<bits/stdc++.h>
using namespace std;
vector<int>lps;///longest 'proper' prefix,suffix
///The failure function: i,e where to go if characters fail to match.
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

vector<int> KMPsearch(string text,int n,string pat,int m)
{
    vector<int>in;///indices of matches
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
    return in;
}

int main()
{
    string text,pat;
    cin>>text>>pat;
    int n=text.length(),m=pat.length();
    lps=vector<int>(m);
    computeLPS(pat,m);
    vector<int> hu=KMPsearch(text,n,pat,m);
    for(int i=0;i<hu.size();i++)
    {
        cout<<hu[i]<<" ";
    }
    return 0;
}

