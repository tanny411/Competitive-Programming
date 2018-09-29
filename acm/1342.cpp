#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define LLU unsigned long long

#define fs first
#define sc second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    double Hn[5002];
    Hn[1]=1;
    for(int i=2;i<=5000;i++)
    {
        Hn[i]=Hn[i-1]+1/(1.0*i);
    }
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double W=0,W1=0,W2=0,cnt=0;
        for(int i=0;i<n;i++)
        {
            double a;
            int b;
            cin>>a>>b;
            if(b==1) {
                cnt++;
                W1+=a;
            }
            else W2+=a;
            W+=a;
        }
//        W/=n;
//        if(cnt) W1/=cnt;
//        double ans=1.0*W*Hn[n]*n;
//        if(cnt) ans-=(Hn[n]-1)*W1*cnt;
///same thing really
        //double ans=W*Hn[n]-W1*(Hn[n]-1);
///also the same
        double ans=W1+W2*Hn[n];
        cout<<"Case "<<test++<<": "<<fixed<<setprecision(10)<<ans<<endl;
    }
    return 0;
}

