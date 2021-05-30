#ifndef QUADRATIC_H
#define QUADRATIC_H

enum SOLUTION_TYPE {
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    ANY_VALUE,
    OVERFLOW
};

typedef struct _Roots {
    double x1;
    double x2;
    enum SOLUTION_TYPE solution_type;
} Roots;

Roots quadratic(double a, double b, double c);

void print_and_solve_equation(double a, double b, double c);

#endif // QUADRATIC_H
