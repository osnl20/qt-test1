#include <stdio.h>
#include <math.h>

#include "quadratic.h"

Roots quadratic(double a, double b, double c)
{
    Roots result = {.solution_type = NO_ROOTS, .x1 = 0.0, .x2 = 0.0};

    if( a == 0.0) {
        if( b == 0.0 ) {
            if( c == 0.0 ) {
                result.solution_type = ANY_VALUE;
            }
        } else {
            result.solution_type = ONE_ROOT;
            result.x1 = -c/b;
            if( !isfinite(result.x1) ) {
                result.solution_type = CALCULATION_OVERFLOW;
            }
        }
        return result;
    }

    double d = b*b - 4*a*c;
    if( d > 0.0 ) {
        result.solution_type = TWO_ROOTS;
        result.x1 = (-b-sqrt(d))/a/2.0;
        result.x2 = (-b+sqrt(d))/a/2.0;
        if(result.x1 > result.x2) {
            double z = result.x1;
            result.x1 = result.x2;
            result.x2 = z;
        }
    } else if ( d == 0.0 ) {
        result.solution_type = ONE_ROOT;
        result.x1 = result.x2 = -b/a/2.0;
    }
    if( !isfinite(d) || !isfinite(result.x1) || !isfinite(result.x2) ) {
        result.solution_type = CALCULATION_OVERFLOW;
    }

    return result;
}

Roots print_and_solve_equation(double a, double b, double c) {
    printf("Уравнение: %f * x^2 + %f * x + %f\n", a, b, c);
    Roots result = quadratic(a, b, c);
    switch(result.solution_type) {
    case NO_ROOTS:
        printf("Нет корней\n");
        break;
    case ONE_ROOT:
        printf("Один корень: x = %f\n", result.x1);
        break;
    case TWO_ROOTS:
        printf("Два корня: x1 = %f, x2 = %f\n", result.x1, result.x2);
        break;
    case ANY_VALUE:
        printf("Вырожденный случай, подходит любое значение x\n");
        break;
    case CALCULATION_OVERFLOW:
        printf("Произошла ошибка вычисления\n");
        break;
    }
    puts("");
    return result;
}
