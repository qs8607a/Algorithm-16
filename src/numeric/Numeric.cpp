#include "Numeric.h"

double
Numeric::sqrt(double c)
{
    if ( x < 0 )
        return 0;
    // TODO return NaN here

    // Newton's method
    // f(x) = f(x0) + (x-x0)*f'(x0) = 0
    // x1 = x0 - f(x0)/f'(x0)
    //
    // we have f(x) = x*x - c
    // so f'(x) = 2*x 
    // then we have iteration function:
    //  x1 = x0 - (x0*x0 - c)/(2*x0)
    //  x1 = (c/x0 + x0)/2.0
    double tol = 1e-15;
    double t = c;
    while ( abs(t - c/t) > tol * t)
        t = ( c/t + t) / 2.0;
    return t;
}
