#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;
    cin>>t;
    while(t--){
        string s, link, curr="http://www.lightoj.com/";
        stack<string>fr,bk;
        cout<<"Case "<<cas++<<":\n";
        while(true){
            cin>>s;
            if(s=="QUIT") break;
            if(s=="VISIT") {
                cin>>link;
                while(!fr.empty()) fr.pop();
                bk.push(curr);
                curr=link;
                cout<<curr<<endl;
            }
            else if(s=="BACK"){
                if(bk.empty()) cout<<"Ignored\n";
                else{
                    fr.push(curr);
                    curr = bk.top();
                    bk.pop();
                    cout<<curr<<endl;
                }
            }
            else{
                if(fr.empty()) cout<<"Ignored\n";
                else{
                    bk.push(curr);
                    curr = fr.top();
                    fr.pop();
                    cout<<curr<<endl;
                }
            }

        }
    }

    return 0;
}