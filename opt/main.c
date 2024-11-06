#include <stdio.h>
#include <math.h>
#include "elementary.h"
#include "pow.h"

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

int main() {
    double ans = sen(M_PI / 4);
    printf("sen: %lf\n", ans);
    
    ans = sin(M_PI / 4);
    printf("sin: %lf\n", ans);

    ans = iterative_opt_pow(2.0, 10.0);
    printf("pow: %lf\n", ans);
}