#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define LL long long
#define LLU unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;

int main()
{
    string s,str;
    while(getline(cin,s))
    {
        str=s;
        int n=s.length();
        if(n<=0) break;
        int ara[30],flag[30],post[30];
        int first=0,op=1;
        for(int i=0;i<26;i++){
            flag[i]=post[i]=0;
            ara[i]=i+1;
        }
        ///pre
        for(int i=2;i<n;i++){
               if(isalpha(s[i])){
                    int j=i-1;
                    while(j>=0 && s[j]==' ') j--;
                    if(j>0 && s[j]==s[j-1]){
                        if(s[j]=='+') {ara[ s[i]-'a' ]++;}
                        else if(s[j]=='-') {ara[ s[i]-'a' ]--;}
                        s[j]=s[j-1]=' ';
                    }
               }
        }
        ///post
        for(int i=0;i<n-1;i++){
               if(isalpha(s[i])){
                    int j=i+1;
                    while(j<n && s[j]==' ') j++;
                    if(j<n-1 && s[j]==s[j+1]){
                        if(s[j]=='+') {post[ s[i]-'a' ]++;}
                        else if(s[j]=='-') {post[ s[i]-'a' ]--;}
                        s[j]=s[j+1]=' ';
                    }
               }
        }
        int ans=0;
        //cout<<s<<endl;
        //cout<<"   "<<in+1<<endl;
        for(int i=0;i<n;i++){
            if(isalpha(s[i]))
            {
                flag[s[i]-'a']=1;
                if(op==1) ans+=ara[s[i]-'a'];
                else ans-=ara[s[i]-'a'];
            }
            if(s[i]=='+') op=1;
            else if(s[i]=='-') op=2;
        }
        cout<<"Expression: "<<str<<endl;
        cout<<"    value = "<<ans<<endl;
        for(int i=0;i<26;i++){
            if(flag[i]){
                cout<<"    "<<(char)(i+'a')<<" = "<<ara[i]+post[i]<<endl;
            }
        }
    }
    return 0;
}
