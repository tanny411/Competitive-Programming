#include<bits/stdc++.h>
#define fs first
#define sc second
using namespace std;

#define LEN 50000
#define LG 20

///suffix array stuff
int P[LEN][LG],suff[LEN];
pair<pair<int,int>,int>L[LEN];

///kmp stuff
int lps[LEN];///longest prefix,suffix
int in[LEN];///indices of matches

bool cmp(pair< pair<int,int> , int >a,pair< pair<int,int> , int >b){
    if(a.fs.fs!=b.fs.fs) return a.fs.fs<b.fs.fs;
    else return a.fs.sc<b.fs.sc;
}

///suffix array
void suffAra(string s,int n){
    for(int i=0;i<n;i++){
        P[i][0]=s[i]-'a';
    }
    int step=1;
    for(int j=1;j<n;j<<=1,step++){
        for(int i=0;i<n;i++){
            L[i].sc=i;
            L[i].fs.fs=P[i][step-1];
            L[i].fs.sc=(i+j<n)?P[i+j][step-1]:-1;
        }
        sort(L,L+n,cmp);
        P[L[0].sc][step]=0;
        for(int i=1;i<n;i++){
            P[L[i].sc][step]=(L[i].fs==L[i-1].fs)?P[L[i-1].sc][step]:i;
        }
    }
    step--;
    for(int i=0;i<n;i++){
        suff[P[i][step]]=i;
    }
}
int LCP(int a,int b,int n){
    ///longest common prefix of a and b index suffix of the string from suffix array, i.e index of suffix array
    ///n is the length of the original string
    if(a<0 || b<0) return 0;
    a=suff[a];
    b=suff[b];
    int lg=ceil(log2(n))-1;
    int lcp=0;
    for(int i=lg;i>=0&&a<n&&b<n;i--){
        if(P[a][i]==P[b][i]){
            a+=(1<<i);
            b+=(1<<i);
            lcp+=(1<<i);
        }
    }
    return lcp;
}

///kmp
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
void KMPsearch(string text,int n,string pat,int m)
{
    memset(in,-1,sizeof(in));

    int i=0,j=0;
    while(i<n)
    {
        if(text[i]==pat[j]) i++,j++;
        if(j==m) in[i-j]=i-j,j=lps[j-1];
        else if(i<n && text[i]!=pat[j])
        {
            if(j>0) j=lps[j-1];
            else i++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,test=1;
    cin>>t;
    while(t--){
        string text,pat;
        cin>>text>>pat;

        int n=text.length(),m=pat.length();


        ///KMP
        computeLPS(pat,m);
        KMPsearch(text,n,pat,m);

        ///in[index]=immediate right index where 'pat' string starts
        if(in[n-1]==-1) in[n-1]=n;
        for(int i=n-2;i>=0;i--){
            if(in[i]!=-1) continue;
            else in[i]=in[i+1];
        }

        suffAra(text,n);

        int ans=0;
        ///find how many distinct substrings of A that don't contain B as a substring.
        for(int i=0;i<n;i++){
            int k=min(n,in[suff[i]]+m-1)-suff[i]-LCP(i,i-1,n);
            if(k>0) ans+=k;
        }

        cout<<"Case "<<test++<<": "<<ans<<endl;
    }
    return 0;
}

