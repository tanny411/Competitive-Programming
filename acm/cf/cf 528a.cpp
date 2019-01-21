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

using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    int t,test=1;
    string s;
    cin>>s;
    int n=s.length(),h;
    if(n%2==0) h=n/2 -1;
    else h=n/2;
    char ara[n+2];
    ara[0]=s[h];
    for(int i=h+1,j=1;i<n;i++,j+=2){
        ara[j]=s[i];
    }
    for(int i=h-1,j=2;i>=0;i--,j+=2){
        ara[j]=s[i];
    }
    ara[n]=0;
    puts(ara);
    return 0;
}

