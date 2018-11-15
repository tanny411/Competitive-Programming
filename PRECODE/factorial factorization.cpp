ll factorial_factor(int n)
{
    ll ans=1;

    for(int i=0;i<SZ(prime) && prime[i]<=n;i++)
    {
        int nn=n;
        ll sum=0;
        while(nn/prime[i])
        {
            sum+=nn/prime[i];
            nn/=prime[i];
        }
        ///sum is the power of the prime in the factorial
    }
    return ans;
}
