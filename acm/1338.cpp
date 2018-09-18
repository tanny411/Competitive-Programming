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

int main(){
    int t,test=1;
    cin>>t;
    getchar();
    while(t--)
    {
        string a,b;
        getline(cin,a);
        //cout<<"             a= "<<a;
        getline(cin,b);
        //cout<<"             b= "<<b;
        vector<int>fr(26);
        for(int i=0;i<a.length();i++) if(isalpha(a[i])) fr[ tolower(a[i])-'a' ]++;
        swap(a,b);
        for(int i=0;i<a.length();i++) if(isalpha(a[i])) fr[ tolower(a[i])-'a' ]--;
        int f=0;
        for(int i=0;i<26;i++) if(fr[i]!=0) {f=1; break;}
        cout<<"Case "<<test++<<": "<<(f==1?"No":"Yes")<<"\n";
    }
    return 0;
}
/**
3
Tom Marvolo Riddle
I am Lord Voldemort
I am not Harry Potter
Hi Pretty Roar to man
Harry and Voldemort
Tom and Jerry and Harry
*/
