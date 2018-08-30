#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define fs first
#define sc second

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    pii s=pii(-1,-1),e;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            if(ch=='B')
            {
                if(s==pii(-1,-1)) s=pii(i,j);
                e=pii(i,j);
            }
        }
    }
    //cout<<s.fs<<" "<<e.fs<<endl;
    cout<<((s.fs+e.fs)/2) + 1<<" "<<((s.sc+e.sc)/2) + 1<<endl;
    return 0;
}
