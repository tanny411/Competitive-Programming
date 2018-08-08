#include <bits/stdc++.h>
using namespace std;
int del(vector<int>pages, vector<int>cur, int n, int index)
{
    int res =-1, farthest=index;
    for (int i = 0; i < cur.size(); i++)
    {
        int j;
        for (j = index; j < pn; j++)
        {
            if (cur[i] == pg[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == pn) return i;
    }
    return (res == -1) ? 0 : res;
}

void optimalPage(vector<int>pages, int n, int capacity)
{
    vector<int>cur;
    int fault = 0;
    for (int i = 0; i < n; i++)
    {
        int f=0;
        for (int j=0;j<cur.size(); i++)
        {
            if (cur[j] == pages[i]){f=1;break;}
        }
        if(f) continue;
        if (cur.size()<n) cur.push_back(pages[i]);
        else
        {
            int j=del(pages,cur,n, i + 1);
            cur[j]=pages[i];
        }
        fault++;
    }
}
int main()
{
    int capacity ,n ;
    cin>>n>>capacity;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout << optimal_Algo(v, n, capacity);

    return 0;
}
