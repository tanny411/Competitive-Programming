#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;

    int ara[]={4,8,15,16,23,42};
    int nara[10];
    int map[1000][2];

    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            if(i==j) continue;
            //cout<<ara[i]<<" x "<<ara[j]<<" = "<<ara[i]*ara[j]<<endl;
            map[ara[i]*ara[j]][0]=ara[i];
            map[ara[i]*ara[j]][1]=ara[j];
        }
    }
    cout<<"? 1 2"<<endl;
    int x;
    cin>>x;
    cout<<"? 2 3"<<endl;
    int y;
    cin>>y;

    int a,b,c;
    if(map[x][0]==map[y][0]) a=map[x][1],b=map[x][0],c=map[y][1];
    else if(map[x][0]==map[y][1]) a=map[x][1],b=map[x][0],c=map[y][0];
    else if(map[x][1]==map[y][1]) a=map[x][0],b=map[x][1],c=map[y][0];
    else if(map[x][1]==map[y][0]) a=map[x][0],b=map[x][1],c=map[y][1];

    nara[1]=a;
    nara[2]=b;
    nara[3]=c;

    cout<<"? 4 5"<<endl;
    cin>>x;
    cout<<"? 5 6"<<endl;
    cin>>y;

    if(map[x][0]==map[y][0]) a=map[x][1],b=map[x][0],c=map[y][1];
    else if(map[x][0]==map[y][1]) a=map[x][1],b=map[x][0],c=map[y][0];
    else if(map[x][1]==map[y][1]) a=map[x][0],b=map[x][1],c=map[y][0];
    else if(map[x][1]==map[y][0]) a=map[x][0],b=map[x][1],c=map[y][1];

    nara[4]=a;
    nara[5]=b;
    nara[6]=c;

    cout<<"!";
    for(int i=1;i<=6;i++) cout<<" "<<nara[i];
    cout<<endl;

    return 0;
}