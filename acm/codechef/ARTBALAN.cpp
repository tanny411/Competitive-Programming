#include<bits/stdc++.h>
#define pb push_back
#define Pb pop_back
#define fs first
#define sc second
#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define MOD 1000000007
#define LL long long
#define LLU unsigned long long
#define eps .0000001
#define zero 0.0000000000000001
#define floatless(a,b) ( (a-b)<=eps )
#define floatequal(a,b) ( floatless(a,b) && floatless(b,a) )
#define incircle_r(a,b,c) 2*area(triangle)/perimeter(triangle)
#define circumcircle_R(a,b,c) a*b*c/sqrt( (a+b+c)*(a+b-c)*(b+c-a)*(c+a-b) )
#define circumcircle_2R_sinelaw a/sinA
#define triarea(a,b,c) sqrt( (a+b+c)*(b+c-a)*(a-b+c)*(a+b-c) )/9
#define mediantoarea(a,b,c) (4/3)*triarea(a,b,c)
/*----------------------Graph Moves----------------*/
//const int fx[]= {+1,-1,+0,+0};
//const int fy[]= {+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

using namespace std;

int main()
{
    int t,cas=1;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.length();
        vector<int>divs;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                divs.pb(i);
                if((n/i)!=i) divs.pb(n/i);
            }
        }
        sort(divs.begin(),divs.end());

        vector<int>fl(30);
        for(int i=0;i<n;i++) fl[s[i]-'A']++;
        vector<int>lt;
        for(int i=0;i<26;i++) if(fl[i]>0) lt.pb(fl[i]);
        sort(lt.begin(),lt.end());
        int cnt=lt.size();
        if(lt[0]==lt[cnt-1]) {
            cout<<0<<endl;
            continue;
        }

        int mn=1<<30;
        for(int i=0;i<divs.size();i++){
            int letters=divs[i];
            if(letters>26) break;
            int freq=n/letters;
            int mv=0;
            for(int j=max(0,cnt-letters);j<cnt;j++){
                if(lt[j]<freq) mv+=freq-lt[j];
            }
            if(letters>cnt) mv+=(-cnt+letters)*freq;
            //cout<<letters<<" "<<mv<<endl;
            mn=min(mn,mv);
        }
        cout<<max(mn,0)<<endl;
    }
    return 0;
}