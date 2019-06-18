#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;
int main(){
    freopen ("mr_x.txt","r",stdin);
    freopen ("myfile3.txt","w",stdout);
    int cas=1,t;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        int f;
        if(s.length()==1){
            if(s[0]=='1' || s[0]=='0') f=0;
            else f=1;
        }
        else{
            stack<char>st1,st2;
            for(int i=0;i<s.length();i++){
                if(s[i]!=')' && s[i]!='(') st1.push(s[i]),st2.push(s[i]);//cout<<s[i];
                else if(s[i]==')'){
                    int t1,t2,t3,t4;

                    char x=st1.top();
                    char y=st2.top();
                    st1.pop();
                    st2.pop();

                    // cout<<y;
                    
                    if(x=='x') t1=1;
                    else if(x=='X') t1=0;
                    else if(x=='1') t1=1;
                    else t1=0;

                    if(y=='x') t2=0;
                    else if(y=='X') t2=1;
                    else if(y=='1') t2=1;
                    else t2=0;

                    t3=t1;
                    t4=t2;

                    char ch1=st1.top();
                    char ch2=st2.top();
                    st1.pop();
                    st2.pop();

                    // cout<<ch2;

                    x=st1.top();
                    y=st2.top();
                    st1.pop();
                    st2.pop();

                    // cout<<y<<endl;
                    
                    if(x=='x') t1=1;
                    else if(x=='X') t1=0;
                    else if(x=='1') t1=1;
                    else t1=0;

                    if(y=='x') t2=0;
                    else if(y=='X') t2=1;
                    else if(y=='1') t2=1;
                    else t2=0;

                    // cout<<t1<<x<<t3<<" "<<t2<<y<<t4<<endl;

                    if(ch1=='&') t1&=t3,t2&=t4;
                    if(ch1=='|') t1|=t3,t2|=t4;
                    if(ch1=='^') t1^=t3,t2^=t4;

                    st1.push(t1+'0');
                    st2.push(t2+'0');
                }
            }
            // cout<<st1.size()<<" "<<st2.size()<<endl;
            // cout<<st1.top()<<" "<<st2.top()<<endl;
            if(st1.top()==st2.top()) f=0;
            else f=1;
        }
        cout<<"Case #"<<cas++<<": "<<f<<endl;
    }

    return 0;
}