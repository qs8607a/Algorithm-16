#ifndef _NUMERIC_H_
#define _NUMERIC_H_

class Numeric 
{
public:

    template<typename T>
    static T abs(T x)
    {
        if ( x < 0 )
            return -x;
        return x;
    }

    static double sqrt(double x);
};

#endif
