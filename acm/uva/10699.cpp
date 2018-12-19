#include<bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007
#define ll long long
#define llu unsigned long long
#define eps .0000001
#define zero 0.0000000000000001
#define floatless(a,b) ( (a-b)<=eps )
#define floatequal(a,b) ( floatless(a,b) && floatless(b,a) )
#define incircle_r(a,b,c) 2*area(triangle)/perimeter(triangle)
#define circumcircle_R(a,b,c) a*b*c/sqrt( (a+b+c)*(a+b-c)*(b+c-a)*(c+a-b) )
#define circumcircle_2R_sinelaw a/sinA
#define triarea(a,b,c) sqrt( (a+b+c)*(b+c-a)*(a-b+c)*(a+b-c) )/9
#define mediantoarea(a,b,c) (4/3)*triarea(a,b,c)
using namespace std;

const int Max=1002;

int flag[Max+2];
vector<int>primes;

void sieve()
{
    int i,j,k,sq=sqrt(Max);
//    flag[0]=flag[1]=1;
//    for(i=4;i<Max;i+=2) flag[i]=1;
    primes.pb(2);
    for(i=3;i<Max;i+=2)
    {
        if(!flag[i])
        {
            primes.pb(i);
            if(i>sq) continue;
            for(j=i*i,k=i+i ; j<Max ;j+=k)
            {
                flag[j]=1;
            }
        }
    }
}


int main()
{
    sieve();
    int x;
    int l=primes.size();
    while(cin>>x && x)
    {
        int y=x;
        int cnt=0;
        for(int i=0;i<l && primes[i]*primes[i]<=x;i++)
        {
            if(x%primes[i]==0)
            {
                cnt++;
                while(x%primes[i]==0) x/=primes[i];
            }
        }
        if(x) cnt++;
        printf("%d : %d\n",y,cnt);
    }
    return 0;
}
