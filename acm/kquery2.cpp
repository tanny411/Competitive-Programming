#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define f(i,a,b) for(int i = (a); i <= (b); i++)

const int BLOCK = 506;
int A[30005], N, Q, T[180][10005];
using namespace std;

void update(int t, int x, int v)
{
    while(x > 0)
    {
        T[t][x] += v;
        x -= x&-x;
    }
}

int query(int t, int x)
{
    int ret = 0;
    while(x <= 10000)
    {
        ret += T[t][x];
        x += x&-x;
    }
    return ret;
}

int main()
{
    cin >> N;

    f(i,1,N)
    {
        scanf("%d", &A[i]);
        update(i/BLOCK,A[i],1);
    }

    cin >> Q;

    while(Q--)
    {
        int t;
        scanf("%d", &t);

        if(!t)
        {
            int x, v;
            scanf("%d %d", &x, &v);
            update(x/BLOCK,A[x],-1);
            A[x] = v;
            update(x/BLOCK,v,1);
        }
        else
        {
            int l,r,k;
            scanf("%d %d %d", &l, &r, &k);
            int ans = 0;
            while(l%BLOCK != 0 && l <= r) ans += A[l++] > k;
            while(r%BLOCK != BLOCK-1 && l <= r) ans += A[r--] > k;
            if(r>l)
            {
                int bl = l/BLOCK;
                int br = r/BLOCK;
                f(b,bl,br) ans += query(b,k+1);
            }
            printf("%d\n", ans);
        }
    }
}
