#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>low(n),high(n),close(n);
    for(int i=0;i<n;i++){
        cin>>low[i];
    }
    for(int i=0;i<n;i++){
        cin>>high[i];
    }
    for(int i=0;i<n;i++){
        cin>>close[i];
    }
    int gapup=0;
    int gapdown=0;
    for(int i=1;i<n;i++){
        if(low[i]>close[i-1]) gapup++;
        if(high[i]<close[i-1]) gapdown++;
    }
    cout<<gapup<<" "<<gapdown<<endl;
    return 0;
}
