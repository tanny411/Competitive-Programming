#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int tree[100009];

void update(int ix, int val, int n){
    while(ix<=n){
        tree[ix]+=val;
        ix+=(ix&(-ix));
    }
}

int query(int ix){
    int sum=0;
    while(ix>0){
        sum+=tree[ix];
        ix-=(ix&(-ix));
    }
    return sum;
}

int main(){

    int cas=1,t;
    scanf("%d", &t);
    while(t--){
        char s[100009];
        int q, n;

        scanf("%s", s);
        n = strlen(s);
        for(int i=0;i<=n;i++) tree[i]=0;

        scanf("%d", &q);
        printf("Case %d:\n", cas++);

        while(q--){
            char query_type;
            getchar();
            scanf("%c", &query_type);
            if(query_type=='I'){
                int range_i, range_j;
                scanf("%d%d", &range_i, &range_j);
                // 1-indexed
                update(range_j+1, 1, n);
                update(range_i, -1, n);
            }
            else{
                int index;
                scanf("%d", &index);
                int ans = query(index);
                if(ans%2==0) printf("%c\n", s[index-1]);
                else{
                    printf("%d\n", 1-(s[index-1]-'0'));
                }
            }
        }
    }

    return 0;
}