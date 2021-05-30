#include <math.h>

#include "quadratic.h"

Roots quadratic(double a, double b, double c)
{
    Roots result = {.rootsCount = 0, .x1 = 0.0, .x2 = 0.0};
    double d = b*b - 4*a*c;
    if( d > 0.0 ) {
        result.rootsCount = 2;
        result.x1 = (-b-sqrt(d))/a/2.0;
        result.x2 = (-b+sqrt(d))/a/2.0;
        if(result.x1 > result.x2) {
            double z = result.x1;
            result.x1 = result.x2;
            result.x2 = z;
        }
    } else if ( d == 0.0 ) {
        result.rootsCount = 1;
        result.x1 = result.x2 = -b/a/2.0;
    }

    return result;
}
