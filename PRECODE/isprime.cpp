#include<bits/stdc++.h>
using namespace std;


int is_prime(int n)
{
    int i,root;
    if(n<2) return 0;
    else if(n==2) return 1;
    else if(n%2==0) return 0;
    else{
        root=sqrt(n);
        for(int i=3;i<=root;i+=2){
            if(n%i==0) return 0;
        }
        return 1;
    }
}

int main()
{
    return 0;
}
