/*FIFO page replacement algorithm*/
#include<bits/stdc++.h>
using namespace std;

int FIFO_Algo(vector<int>pages, int n, int capacity)
{
    unordered_set<int> s;
    queue<int> indexes;
    int page_faults = 0;
    for (int i=0; i<n; i++)
    {
        if (s.size() < capacity)
        {
            if (s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);
                page_faults++;
                indexes.push(pages[i]);
            }
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int val = indexes.front();
                indexes.pop();
                s.erase(val);
                s.insert(pages[i]);
                indexes.push(pages[i]);
                page_faults++;
            }
        }
    }

    return page_faults;
}
int main()
{
    int capacity ,n ;
    cin>>n>>capacity;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout << FIFO_Algo(v,n,capacity);
    return 0;
}
