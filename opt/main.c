#include <stdio.h>
#include <math.h>
#include "ex.h"
#include "elementary.h"
#include "pow.h"

int main() {
    double x;
    printf("Valor de x: ");
    scanf("%lf", &x);
    double y = ex(x);
    double error = fabs(y - exp(x));

    printf("Error: %lf\n", error);
}