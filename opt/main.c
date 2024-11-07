#include <stdio.h>
#include <math.h>
#include "ex.h"
#include "elementary.h"
#include "pow.h"

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

int main() {
    double x = 5.5;
    double y = ex(x);
    double error = fabs(y - exp(x));

    printf("Error: %lf\n", error);
}