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

using namespace std;
/*
The first person has a 100% chance of a unique number (of course)
The second has a (1 – 1/365) chance (all but 1 number from the 365)
The third has a (1 – 2/365) chance (all but 2 numbers)
The 23rd has a (1 – 22/365) (all but 22 numbers)
p(different) = 1 * (1-1/d) * (1 - 2/d) * (1 - 3/d) ....
p(exist a match) = 1 - p(different)
*/
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        double n,p=1;
        cin>>n;
        int i;
        for(i=0;p>0.5;i++)
        {
            p*=(1.0-i/n);
        }
        cout<<"Case "<<test++<<": "<<i-1<<endl; //i=n-1 means n people, i-- , subtracting myself
    }
    return 0;
}

