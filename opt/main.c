#include <stdio.h>
#include <math.h>
#include "elementary.h"
#include "pow.h"

int main() {
    /*
    double x;
    printf("x value: ");
    scanf("%lf", &x);

    double res1 = ex(x);
    double res2 = exp(x);
    
    double res1 = sen(M_PI / 2);
    double res2 = sin(M_PI / 2);
    
    double res1 = _cos(M_PI / 4);
    double res2 = cos(M_PI / 4);
    

    double res1 = _sqrt(x);
    double res2 = sqrt(x);
    double error = fabs(res1 - res2);
    
    printf("Result 1: %lf\n", res1); 
    printf("Result 2: %lf\n", res2);
    printf("Error: %lf\n", error);
    */

    double x = 2.0;
    long y = 13;

    double res = iterative_opt_pow(x, y);

    printf("Res: %lf\n", res);
}