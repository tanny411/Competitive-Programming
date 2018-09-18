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
bool is_leapyear(int y)
{
    if( !(y % 100) ) {
        if( !(y % 400) )
            return 1;
        else
            return 0;
    }
    else if( !(y % 4))
        return 1;
    else
        return 0;
}
int main()
{
    int t,test=1;
    scanf("%d",&t);
    while(t--)
    {
        char s[100];
        int day,year1,month,year2;
        scanf(" %s %d, %d",s,&day,&year1);
        int ans=0;
        if( ( (year1%4==0 && year1%100!=0) || year1%400==0 )/*is_leapyear(year1)*/ && ( (s[0]=='J' && s[1]=='a') || s[0]=='F')) ans++;
        scanf(" %s %d, %d",s,&day,&year2);
        if( ( (year2%4==0 && year2%100!=0) || year2%400==0 )/*is_leapyear(year2)*/ && ( (s[0]=='J' && s[1]=='a') || (s[0]=='F' && day<29) ) ) ans--;
        ans+=(year2/4 - year2/100 + year2/400)-(year1/4 - year1/100 + year1/400);
        cout<<"Case "<<test++<<": "<<ans<<endl;
    }
    return 0;
}
/**
4
January 12, 2012
March 19, 2012
August 12, 2899
August 12, 2901
August 12, 2000
August 12, 2005
February 29, 2004
February 29, 2012
*/
