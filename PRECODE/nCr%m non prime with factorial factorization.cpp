//lightoj 1318
void factorial_factorization(ll n, ll sign)
{
    for(int i=0;i<sz && prime[i]<=n;i++)
    {
        ll temp=n;
        while(temp) temp/=prime[i],cnt[i]+=sign*temp;
    }
}
ll C(ll n,ll r, ll m)
{
    //nCr % M and M is not prime: prime factorize nCr then for each power of prime p, do bigmod with M. now to prime factorize nCr,
    //{ prime powers of n! - prime powers of r! - prime powers of (n-r)! }
    ll ans=1;
    cnt=vector<int>(sz);
    factorial_factorization(n,1);
    factorial_factorization(r,-1);
    factorial_factorization(n-r,-1);
    for(int i=0;i<sz;i++)
    {
        ans=(ans*bg(prime[i],cnt[i],m))%m;
    }
    return ans;
}
