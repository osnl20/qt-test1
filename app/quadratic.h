#ifndef QUADRATIC_H
#define QUADRATIC_H

typedef struct _Roots {
    double x1;
    double x2;
    int rootsCount;
} Roots;

Roots quadratic(double a, double b, double c);

#endif // QUADRATIC_H
