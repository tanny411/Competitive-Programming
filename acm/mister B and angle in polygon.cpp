#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
int main(){
    double n,th;
    cin>>n>>th;
    double cent=360/n;
    double angle=cent;
    int in=-1;
    double mn=1<<30;
    for(int i=n-1;i>=2;i--,angle+=cent){
        if(mn>abs(th-angle/2) ){
            mn=abs(th-angle/2);
            in=i;
        }
    }
    cout<<in<<" 1 "<<n<<endl;
}
