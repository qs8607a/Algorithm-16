
#include "Number.h"

int
Number::Number(int p, int q)
{
    if( q == 0)
        return p;
    int r = p % q;
    return gcd(q, r);
}
