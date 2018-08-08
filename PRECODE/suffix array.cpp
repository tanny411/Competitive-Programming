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

///O( n(log n)^2 )

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
        sort(L,L+n,suff_cmp);///perform counting or radix sort here to reduce complexity
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
    string s;
    cin>>s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    makeSuffAra(s);
    for(int i=0;i<s.length();i++){
        cout<<suffara[i]<<endl;
    }
    return 0;
}

