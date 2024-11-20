#include "elementary.h"

double horner(const double* A, double x, const int n) {
    double res = A[n-1];

    for (int i = n - 2; i >= 0; i--)
        res = res * x + A[i];

    return res;
}

double sen(double x) {    
    static const double SEN_A = -0.16666666666666666;  // -1.0 / 6.0
    static const double SEN_B = 0.008333333333333333;  // 1.0 / 120.0
    static const double SEN_C = -0.0001984126984126984; // -1.0 / 5040.0
    static const double SEN_D = 0.0000027557319223985893; // 1.0 / 362880.0
    
    static const double SEN_ARR[] = {1.0, SEN_A, SEN_B, SEN_C, SEN_D};
    static const int SEN_N = sizeof(SEN_ARR) / sizeof(SEN_ARR[0]);

    double y = x * x;

    return x * (horner(SEN_ARR, y, SEN_N));
}

double _cos(double x) {    
    static const double COS_A = -0.5;  // -1.0 / 2.0
    static const double COS_B = 0.041666666666666664;  // 1.0 / 24.0
    static const double COS_C = -0.0013888888888888887; // -1.0 / 720.0
    static const double COS_D = 0.0000248015873015873;  // 1.0 / 40320.0
    
    static const double COS_ARR[] = {1.0, COS_A, COS_B, COS_C, COS_D};
    static const int COS_N = sizeof(COS_ARR) / sizeof(COS_ARR[0]);

    double y = x * x;

    return horner(COS_ARR, y, COS_N);
}


double ex(double x) {
    static const double E_K2 = 0.5; // 1.0 / 2.0
    static const double E_K3 = 0.16666666666666666; // 1.0 / 6.0
    static const double E_K4 = 0.041666666666666664; // 1.0 / 24.0
    
    static const double E_ARR[] = {1.0, 1.0, E_K2, E_K3, E_K4};
    static const int E_N = sizeof(E_ARR) / sizeof(E_ARR[0]);

    return horner(E_ARR, x, E_N);
}

double sqrt(double a) {
    return a;
}
