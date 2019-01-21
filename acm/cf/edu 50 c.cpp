#include "bits/stdc++.h"
using namespace std;

long long dp[20][4];
void getDigits(long long x, vector <int> &digit)
{
	while (x)
	{
		digit.push_back(x%10);
		x /= 10;
	}
}

long long digitSum(int idx, int tight,vector <int> &digit,int koyta)
{
	if (idx == -1) return 1ll;
	if (dp[idx][koyta] != -1 and tight != 1) return dp[idx][koyta];
	long long ret = 0;
	int k = (tight)? digit[idx] : 9;
    if(koyta>=3) k=0;
	for (int i = 0; i <= k ; i++)
    {
        int newTight = (digit[idx] == i)? tight : 0;
        ret += digitSum(idx-1, newTight, digit,i>0?koyta+1:koyta);
    }

	if (!tight) dp[idx][koyta] = ret;

	return ret;
}
long long rangeDigitSum(long long a, long long b)
{
	vector<int> digitA;
	getDigits(a-1, digitA);
	long long ans1 = digitSum(digitA.size()-1, 1, digitA,0);

	vector<int> digitB;
	getDigits(b, digitB);
	long long ans2 = digitSum(digitB.size()-1, 1, digitB,0);

	return (ans2 - ans1);
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int t;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        cout<<rangeDigitSum(a, b)<<endl;
    }
    /**
    1
    1
    1000000000000000000
    */
	return 0;
}

