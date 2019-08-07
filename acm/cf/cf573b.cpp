#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int ok(int a,int b,int c){
    int ara[3]={a,b,c};
    sort(ara,ara+3);
    return (ara[1]-ara[0]==1 && ara[2]-ara[1]==1);
}

int main(){
    int cas=1,t;

    string card1,card2,card3;
    cin>>card1>>card2>>card3;

    //equal milano
    int ans=1<<30;
    if(card1==card2 && card2==card3) ans=min(ans,0);
    else if(card1==card2 || card1==card3 || card2==card3) ans=min(ans,1);
    else ans=min(ans,2);

    //sequence milano
    if(card1[1]==card2[1] && card2[1]==card3[1] && ok(card1[0]-'0',card2[0]-'0',card3[0]-'0')) ans=min(ans,0);
    else if(card1[1]==card2[1] && abs(card1[0]-card2[0])<=2 || card1[1]==card3[1] && abs(card1[0]-card3[0])<=2 || card3[1]==card2[1] && abs(card3[0]-card2[0])<=2) ans=min(ans,1);
    else ans=min(ans,2);

    cout<<ans<<endl;
    return 0;
}