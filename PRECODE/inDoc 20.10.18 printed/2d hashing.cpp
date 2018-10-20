#include<stack>
#include<vector>
#include<queue>
#include<set>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
#define ull unsigned long long
using namespace std;
///uva 11019
///number of occurances of one matrix in another one
const int maxn = 1000 + 10;
const int seed1 = 131;
const int seed2 = 13131;
const int MOD = 100013;
const int INF = 0x3f3f3f3f;
char s[maxn][maxn],str[maxn];
ull ha[maxn][maxn];
int T;
int n, m, x, y;
int solve(ull aim){
    ull bit = 1;
    for(int i = 1; i <= y - 1; i++)
        bit = bit * seed1;
    for(int i = 1; i <= n; i++){    //Preprocessing hash for each row
        ull sum = 0;
        for(int j = 1; j <= y - 1; j++){
            sum = sum * seed1 + s[i][j];
        }
        for(int j = y; j <= m; j++){
            sum = sum * seed1 + s[i][j];
            ha[i][j - y + 1] = sum;
            sum -= bit * s[i][j - y + 1];
        }
    }
    int ans = 0;
    bit = 1;
    for(int i = 1; i <= x - 1; i++)
        bit = bit * seed2;
    for(int j = 1; j <= m - y + 1; j++){
        ull sum = 0;
        for(int i = 1; i <= x - 1; i++){
            sum = sum * seed2 + ha[i][j];
        }
        for(int i = x; i <= n; i++){
            sum = sum * seed2 + ha[i][j];
            if(sum == aim) ans++;
            sum -= bit * ha[i - x + 1][j];
        }
    }
    return ans;

}
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
            scanf("%s", s[i] + 1);
        scanf("%d%d", &x, &y);
        ull temp, aim = 0;  //First, x*y two dimensional hash.
        for(int i = 1; i <= x; i++){
            scanf("%s", str + 1);
            temp = 0;
            for(int j = 1; j <= y; j++){
                temp = temp * seed1 + str[j];
            }
            aim = aim * seed2 + temp;
        }
        printf("%d\n", solve(aim));
    }
    return 0;
}
