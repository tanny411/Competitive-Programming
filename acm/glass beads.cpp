#include<bits/stdc++.h>
#define pii pair<int,int>
#define fs first
#define sc second
#define pb push_back
using namespace std;

#define LEN 20000 + 5
#define LG 20

int suffara[LEN],P[LEN][LG];
pair< pair<int,int> , int > L[LEN]; ///prev,now and index

bool suff_cmp(pair< pair<int,int> , int >a,pair< pair<int,int> , int >b){
    if(a.fs.fs!=b.fs.fs) return a.fs.fs<b.fs.fs;
    else return a.fs.sc<b.fs.sc;
}

void makeSuffAra(string s,int n){
    for(int i=0;i<n;i++){
        P[i][0]=s[i]-'a';
    }

    int step=1;
    for(int j=1;j<n;step++,j<<=1){
        for(int i=0;i<n;i++){
            L[i].sc=i;
            L[i].fs.fs=P[i][step-1];
            L[i].fs.sc=(i+j<n)?P[i+j][step-1]:1<<30;
        }
        sort(L,L+n,suff_cmp);
        P[L[0].sc][step]=0;
        for(int i=1;i<n;i++){
            P[L[i].sc][step]=(L[i].fs==L[i-1].fs)?P[L[i-1].sc][step]:i;
        }
    }
    step--;
    for(int i=0;i<n;i++){
        suffara[P[i][step]]=i;
    }
}

int main()
{
    ///aaaaa
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>s;
        n=s.length();
        s+=s;
        makeSuffAra(s,n+n);
        for(int i=0;i<n+n;i++){
            //cout<<suffara[i]<<" ";
            if(suffara[i]<n){
                cout<<suffara[i]+1<<endl;
                break;
            }
        }
    }
    return 0;
}
