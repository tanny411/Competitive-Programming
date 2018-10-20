///half point
#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define LL long long
#define LLU unsigned long long

#define fs first
#define sc second

using namespace std;

vector<int>v,temp;
int n,first;

int okay(int p){
    int hobe=1;
    temp[first]=v[first];
    for(int i=first+1;i<n && hobe;i++)
    {
        temp[i]=v[i];
        int x=(temp[i-1]+1)%p;
        if(x==0) x=p;
        if(v[i]==-1) temp[i]=x;
        else if(v[i]!=x) hobe=0;
    }
    if(hobe)
    {
        for(int i=first-1;i>=0 && hobe;i--)
        {
            temp[i]=v[i];
            int x=((temp[i+1]-1)%p+p)%p;
            if(x==0) x=p;
            if(v[i]==-1) temp[i]=x;
            else if(v[i]!=x) hobe=0;
        }
        if(hobe){
            return p;
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int koyta=0;
        first=-1;
        v=temp=vector<int>(n);
        for(int i=0; i<n; i++)
        {
            cin>>v[i];
            if(v[i]>-1){
                koyta++;
                if(first==-1) first=i;
            }
        }
        if(koyta<=1)
        {
            cout<<"inf\n";
            continue;
        }
        if(okay(2147483648)){
            cout<<"inf\n";
            continue;
        }
        int hoise=0;
        for(int p=n; p>0 && hoise==0; p--)
        {
            if(okay(p)) hoise=p;
        }
        if(hoise) cout<<hoise<<endl;
        else cout<<"impossible\n";
    }
    return 0;
}

