#include<iostream>
#include<vector>
#define pb push_back
using namespace std;
int main()
{
    vector<int>v;
    for(int i=0;i<10;i++){
        int x;
        cin>>x;
        v.pb(x);
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}