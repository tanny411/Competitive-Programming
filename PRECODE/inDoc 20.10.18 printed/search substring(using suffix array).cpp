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
/**
The task is to find a string s inside some text t online - we know the text t beforehand, but not the string s.
We can create the suffix array for the text t in O(|t|log|t|) time. Now we can look for the substring s in the following way.
The occurrence of s must be a prefix of some suffix from t. Since we sorted all the suffixes we can perform a binary search for s in p.
Comparing the current suffix and the substring s within the binary search can be done in O(|s|) time,
therefore the complexity for finding the substring is O(|s|log|t|). Also notice that if the substring occurs multiple times in t,
then all occurrences will be next to each other in p. Therefore the number of occurrences can be found with a second binary search,
and all occurrences can be printed easily.
*/
#define LEN 1000 + 5
#define LG log2(LEN) + 2

int suffara[LEN],P[LEN][(int)LG];
pair< pair<int,int> , int > L[LEN]; ///prev,now and index

bool suff_cmp(pair< pair<int,int> , int >a,pair< pair<int,int> , int >b){
    if(a.fs.fs!=b.fs.fs) return a.fs.fs<b.fs.fs;
    else return a.fs.sc<b.fs.sc;
}

void makeSuffAra(string s){
    int n=s.length();
    for(int i=0;i<n;i++){
        P[i][0]=s[i]-'a';
    }

    int step=1;
    for(int j=1;j<n;step++,j<<=1){///power(step-1)<n
        for(int i=0;i<n;i++){
            L[i].sc=i;
            L[i].fs.fs=P[i][step-1];
            L[i].fs.sc=(i+j<n)?P[i+j][step-1]:-1;
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
    int ns,np;
    string s;
    cin>>s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    makeSuffAra(s);
    string p;
    cin>>p;
    ns=s.length();
    np=p.length();
    int ansini=-1,ansfin=-1;
    int lo=0,hi=ns-1;
    while(lo<hi){
        int m=(lo+hi)/2;
        int in=suffara[m];
        int f=-1;
        int i,j;
        for(i=in,j=0;i<ns&&j<np;i++,j++){
            if(s[i]<p[j]) {
                f=0;
                break;
            }
            else if(s[i]>p[j]){
                f=1;
                break;
            }
        }
        if(f==-1 && i==ns && j<np) f=0;
        if(f==-1) ansini=m;
        if(f==0)lo=m+1;
        else if(f==1||f==-1) hi=m;
    }
    if(ansini==-1){
        return 0;
    }
    lo=0;
    hi=ns-1;
    while(lo<hi){
        int m=ceil((lo+hi)/2.0);
        int in=suffara[m];
        int f=-1;
        int i,j;
        for(i=in,j=0;i<ns&&j<np;i++,j++){
            if(s[i]<p[j]) {
                f=0;
                break;
            }
            else if(s[i]>p[j]){
                f=1;
                break;
            }
        }
        if(f==-1 && i==ns && j<np) f=0;
        if(f==-1) ansfin=m;
        if(f==0 || f==-1)lo=m;
        else if(f==1) hi=m-1;
    }
    vector<int>v;
    for(int i=ansini;i<=ansfin;i++){
        v.pb(suffara[i]);
    }
    sort(v.begin(),v.end());
    ///sorted order index from where the pattern starts
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}

