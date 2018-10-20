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

///
#define LEN 15010
#define LG 15
using namespace std;


pair<pii,int>L[LEN];
int P[LEN][LG],suff[LEN];

bool cmp(pair<pii,int>a,pair<pii,int>b){
    if(a.fs.fs==b.fs.fs) return a.fs.sc<b.fs.sc;
    else return a.fs.fs<b.fs.fs;
}
int lcp(int a,int b,int step){
    int ans=0;
    for(int i=step;i>=0;i--){
        if(P[a][i]==P[b][i]){
            ans+=(1<<i);
            a+=(1<<i);
            b+=(1<<i);
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,test=1;
    cin>>t;
    while(t--){
        string a,b,c;
        cin>>a>>b>>c;

        int n=a.length();
        int m=b.length();
        int p=c.length();
        a+='$'+b+'#'+c+'%';
        int len=a.length();

        //cout<<"aysha";
        for(int i=0;i<len;i++){
            P[i][0]=a[i]-'a';
        }
        int step=1;
        for(int j=1;j<len;j*=2,step++){
            for(int i=0;i<len;i++){
                L[i].sc=i;
                L[i].fs.fs=P[i][step-1];
                L[i].fs.sc=(i+j<len)?P[i+j][step-1]:-1000;
            }
            sort(L,L+len,cmp);
            for(int i=0;i<len;i++){
                P[L[i].sc][step]=(i>0 && L[i].fs==L[i-1].fs)?P[L[i-1].sc][step]:i;
            }
        }
        step--;
//        for(int i=0;i<len;i++){
//            suffara[P[i][step]]=i;
//        }
        //cout<<"kamal\n";
        int x=0,y=0,z=0;

        int ANS=0;
        //cout<<"tanny";
        for(int i=3,j=3;i<len;j++,i++){
            while(j<len && (x==0 || y==0 || z==0) ){
                //cout<<"aysha\n";
                int k=L[j].sc;
                if(k<n) x++;
                else if (k<(n+1+m)) y++;
                else z++;
                j++;
            }
            j--;
            if(x==0 || y==0 || z==0) break;
            //cout<<i<<" "<<j<<endl;
            ANS=max(ANS,lcp(L[i].sc,L[j].sc,step));
            int k=L[i].sc;
            if(k<n) x--;
            else if (k<(n+1+m)) y--;
            else z--;
        }
        //cout<<"aise";
        cout<<"Case "<<test++<<": "<<ANS<<endl;
    }
    return 0;
}
