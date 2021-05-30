#include "quadratic.h"

Roots quadratic(double a, double b, double c)
{
    Roots result;
    result.rootsCount = 2;
    result.x1 = a+b+c;
    result.x2 = 0.0;
    return result;
}
