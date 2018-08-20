#include<bits/stdc++.h>
#define pb push_back

using namespace std;

int main()
{
    int x,y,k,t,test=1;
    cin>>t;
    while(t--){
        cin>>x>>k>>y;
        if(y<x) swap(x,y);
        cout<<"case #"<<test++<<": "<<((k>x && k<y)?"Yeah!":"Nah!!")<<endl;
    }


    return 0;
}
