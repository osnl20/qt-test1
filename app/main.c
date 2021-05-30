#include <stdio.h>

#include "myfunc.h"
#include "quadratic.h"

int main() {
    print_and_solve_equation(2.0, 3.0, 5.0);
    print_and_solve_equation(4.0, 4.0, 1.0);
    print_and_solve_equation(-2.0, 3.0, 5.0);
    print_and_solve_equation(0, 0, 0);
    print_and_solve_equation(1, 1e300, 1);

    printf("Hello World!\n");
    return myfunc(2);
}
