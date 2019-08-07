#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    cout<<"aysha\n";
    int arr[4]={1,2,3,4};
    vector<int>v(arr, arr + sizeof(arr)/sizeof(arr[0]));
    cout<<v[upper_bound(v.begin(),v.end(),3)-v.begin()];

    return 0;
}