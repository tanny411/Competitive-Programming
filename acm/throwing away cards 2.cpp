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

///ios_base::sync_with_stdio(false);

using namespace std;

int main()
{
    int n;
    while(cin>>n && n)
    {
        if(n==1){
            cout<<"Discarded cards:\nRemaining card: 1\n";
            continue;
        }
        queue<int>q;
        cout<<"Discarded cards: ";
        for(int i=1;i<=n;i++)
        {
            if(i&1) {
                if(i!=1) cout<<", ";
                cout<<i;
            }
            else q.push(i);
        }
        if(n&1) {q.push(q.front());
        q.pop();}
        while(q.size()>1)
        {
            cout<<", "<<q.front();
            q.pop();
            q.push(q.front());
            q.pop();
        }
        cout<<endl;
        cout<<"Remaining card: "<<q.front()<<endl;
    }
    return 0;
}
