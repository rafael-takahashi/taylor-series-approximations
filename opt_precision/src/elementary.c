#include <stdbool.h>
#include <math.h>
#include "elementary.h"

double horner(const double* A, double x, const int n) {
    double res = A[n-1];

    for (int i = n - 2; i >= 0; i--)
        res = res * x + A[i];

    return res;
}

double handle_sen_large_argument(double x) {
    double abs_x = fabs(x);

    if (M_PI / 4.0 < abs_x && abs_x <= 3.0 * M_PI / 4.0)
        return cos(abs_x - M_PI / 2.0);
    else if (3.0 * M_PI / 4.0 < abs_x && abs_x <= M_PI)
        return sen(M_PI - abs_x);
    else if (M_PI < abs_x && abs_x <= 5.0 * M_PI / 4)
        return -cos(abs_x - M_PI);
    else if (5.0 * M_PI / 4 < abs_x && abs_x <= 7.0 * M_PI / 4)
        return -cos(abs_x - 5.0 * M_PI / 4.0);
    else if (7.0 * M_PI / 4 < abs_x && abs_x <= 2.0 * M_PI)
        return -cos(M_PI - abs_x);
    else {
        double reduced_x = abs_x - 2.0 * floor(abs_x / (2.0 * M_PI)) * M_PI; 
        if (reduced_x > M_PI / 4.0)
            return handle_sen_large_argument(reduced_x);
        else return sen(reduced_x);
    }
}

double sen(double x) {    
    if (fabs(x) > M_PI / 4.0) {
        return handle_sen_large_argument(x);
    } else {
        static const double SEN_A = -0.16666666666666666666666666666667;  // -1.0 / 3!
        static const double SEN_B = 0.00833333333333333333333333333333;  // 1.0 / 5!
        static const double SEN_C = -1.984126984126984126984126984127e-4; // -1.0 / 7!
        static const double SEN_D = 2.7557319223985890652557319223986e-6; // 1.0 / 9!
        static const double SEN_E = -2.5052108385441718775052108385442e-8; // 1.0 / 11!
        
        static const double SEN_ARR[] = {1.0, SEN_A, SEN_B, SEN_C, SEN_D, SEN_E};
        static const int SEN_N = sizeof(SEN_ARR) / sizeof(SEN_ARR[0]);

        double y = x * x;

        return x * (horner(SEN_ARR, y, SEN_N));
    }
}

double _cos(double x) {    
    static const double COS_A = -0.5;  // -1.0 / 2!
    static const double COS_B = 0.04166666666666666666666666666667;  // 1.0 / 4!
    static const double COS_C = -0.00138888888888888888888888888889; // -1.0 / 6!
    static const double COS_D = 2.4801587301587301587301587301587e-5;  // 1.0 / 8!
    static const double COS_E = -2.7557319223985890652557319223986e-7;  // 1.0 / 10!
    static const double COS_F = 2.0876756987868098979210090321201e-9;  // 1.0 / 12!
    
    static const double COS_ARR[] = {1.0, COS_A, COS_B, COS_C, COS_D, COS_E, COS_F};
    static const int COS_N = sizeof(COS_ARR) / sizeof(COS_ARR[0]);

    double y = x * x;

    return horner(COS_ARR, y, COS_N);
}


double e(double x) {
    static const double E_K2 = 0.5; // 1.0 / 2.0
    static const double E_K3 = 0.16666666666666666; // 1.0 / 6.0
    static const double E_K4 = 0.041666666666666664; // 1.0 / 24.0
    
    static const double E_ARR[] = {1.0, 1.0, E_K2, E_K3, E_K4};
    static const int E_N = sizeof(E_ARR) / sizeof(E_ARR[0]);

    return horner(E_ARR, x, E_N);
}

double _sqrt(double a) {
    static const double SQRT_A = 0.5;           // 1/2
    static const double SQRT_B = -0.125;        // -1/8
    static const double SQRT_C = 0.0625;        // 1/16
    static const double SQRT_D = -0.0390625;    // -5/128
    static const double SQRT_E = 0.02734375;    // 7/256
    static const double SQRT_F = -0.0205078125;  // -21/1024
    
    static const double SQRT_ARR[] = {1.0, SQRT_A, SQRT_B, SQRT_C, SQRT_D, SQRT_E, SQRT_F};
    static const int SQRT_N = sizeof(SQRT_ARR) / sizeof(SQRT_ARR[0]);

    double x = a - 1;

    return horner(SQRT_ARR, x, SQRT_N);   
}
