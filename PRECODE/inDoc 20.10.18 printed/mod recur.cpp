long long bg(int base,int pow,int m)
{
    if(pow==0) return 1;
    long long x=bg(base,num/2,m);
    x=(x*x)%m;
    if(pow&1) x=(base*x)%m;
    return x;
}
///recursive
int bigmod ( long long a, int p, int m )
{
    if ( p == 0 )return 1; // If power is 0 ( a ^ 0 ), return 1

    if ( p & 1 ) // If power is odd
    {
        return ( ( a % m ) * ( bigmod ( a, p - 1, m ) ) ) % m;
    }
    else
    {
        long long tmp = bigmod ( a, p / 2, m );
        return ( tmp * tmp ) % m;
    }
}
///iterative
long long bigmod ( long long a, long long p, long long m )
{
    long long res = 1;
    long long x = a;

    while ( p )
    {
        if ( p & 1 ) //p is odd
        {
            res = ( res * x ) % m;
        }
        x = ( x * x ) % m;
        p = p >> 1;
    }

    return res;
}
