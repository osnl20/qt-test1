#include <stdio.h>

#include "myfunc.h"
#include "quadratic.h"

int main()
{
    double a = 2.0, b = 3.0, c = 5.0;
    printf("Quadratic equation: %f * x^2 + %f * x + %f\n", a, b, c);
    Roots result = quadratic(a, b, c);
    printf("Roots count = %d\n", result.rootsCount);
    if(result.rootsCount == 2) {
        printf("x1 = %f\n", result.x1);
        printf("x2 = %f\n", result.x2);
    } else if(result.rootsCount == 1) {
        printf("x = %f\n", result.x1);
    }

    printf("Hello World!\n");
    return myfunc(2);
}
