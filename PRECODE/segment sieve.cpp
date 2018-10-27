/**Bismillahir Rahmanir Rahim.**/

#include <bits/stdc++.h>

using namespace std;

int prime[7809], x=1;

void seivePrime()
{
    char prime_b[46350];
    memset(prime_b, 0, sizeof(prime_b));
    prime_b[1]=1;
    int till = 46349;
    for(int i=4; i<=till; i+=2)
        prime_b[i] = 1;
    int limit = sqrt(till)+1;
    for(int i=3; i<=limit; i+=2)
    {
        if(!prime_b[i])
        {
            for(int j=i*i; j<=till; j+=(i*2))
                prime_b[j] = 1;
        }
    }
    prime[0] = 2;
    for(int i=3; i<=till; i+=2)
        if(!prime_b[i])
            prime[x++] = i;
}
long long segment_prime(long long A, long long B)
{
    if(A==1) A++;
    char segment[B-A+1];
    memset(segment, 0, sizeof(segment));
    long long till = sqrt(B)+1, cnt=0;
    for(long long i=0; i<x && prime[i]<=till; i++)
    {
        long long start = prime[i]*prime[i];
        if(start<A) start = ((A+prime[i]-1)/prime[i])*prime[i];
        for(; start<=B; start += prime[i])
            segment[start-A] = 1;
    }
    if(A<=2 && B>=2) cnt++;
    long long j=A+1;
    if(A%2) j=A;
    for(; j<=B; j+=2)
        if(!segment[j-A])
            cnt++;
    return cnt;
}
int main()
{
    seivePrime();
    int tst;
    scanf("%d", &tst);
    for(int k=1; k<=tst; k++)
    {
        long long a, b, cnt = 0;
        scanf("%lld %lld", &a, &b);
        cnt = segment_prime(a, b);
        printf("Case %d: %lld\n", k, cnt);
    }
    return 0;
}
