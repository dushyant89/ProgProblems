#include<stdio.h>

#define MOD 1000000007
long long modPow(long long a, long long x, long long p) {
    //calculates a^x mod p in logarithmic time.
    long long res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        printf("x=%lld res=%lld a=%lld\n",x,res,a);
        x /= 2;
    }
    return res;
}

int main()
{

    printf("%lld",modPow(2,9,MOD));
    return 1;
}
