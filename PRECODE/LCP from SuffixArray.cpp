#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define llu unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;

#define LEN 10000
#define LG (int)(log2(LEN)) +2
int P[LEN][LG],suff[LEN];
pair<pii,int>L[LEN];

bool cmp(pair< pair<int,int> , int >a,pair< pair<int,int> , int >b){
    if(a.fs.fs!=b.fs.fs) return a.fs.fs<b.fs.fs;
    else return a.fs.sc<b.fs.sc;
}
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
int LCP(int a,int b,int n){///longest common prefix of a and b index suffix of the string from suffix array, i.e index of suffix array
    ///n is the length of the original string
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
int main()
{
    int q,t=1;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        int n=s.length();
        suffAra(s,n);
//        for(int i=0;i<n;i++){
//            cout<<suff[i]<<" ";
//        }
    }
    return 0;
}

