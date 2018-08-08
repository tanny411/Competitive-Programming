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

#define MX 1000000
int phi[MX+2],flag[MX+2];
void sievephi()
{
    for(int i=2;i<=MX;i++)
    {
        phi[i]=i;
    }
    phi[1]=1;
    ///by definition
    flag[0]=flag[1]=1;
    for(int i=2;i<=MX;i++)
    {
        if(!flag[i])
        {
            for(int j=i;j<=MX;j+=i)
            {
                flag[j]=1;
                phi[j]=(phi[j]/i)*(i-1);
            }
        }
    }
}



int main()
{
    return 0;
}

