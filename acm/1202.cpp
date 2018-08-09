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
///ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    int t,test=1;
    scanf("%d",&t);
    while(t--){
        int x,y,a,b;
        scanf("%d%d%d%d",&x,&y,&a,&b);
        string str;
        if(abs(a-x)==abs(b-y)) str="1";
        else if(((a+x)&1) != ((b+y)&1)) str="impossible";
        else str="2";
        printf("Case %d: %s\n",test++,str.c_str());
    }
    while(t--)
    return 0;
}
/**
6
4052 8261 1537 7861
1000000000 1 1 999999999
1000000000 1 2 999999999
1000000000 2 1 999999999
21 10 23 8
46 8 25 29
Case 1: impossible
Case 2: impossible
Case 3: 1
Case 4: 2
Case 5: 1
Case 6: 1
*/
