#include "elementary.h"
#include <stdbool.h>
#include <math.h>
#include "definitions.h"
#include "ieee754.h"
#include "pow.h"

double horner(const double* A, double x, const int n) {
    double res = A[n-1];

    for (int i = n - 2; i >= 0; i--)
        res = res * x + A[i];

    return res;
}

double handle_sen_large_argument(double x) {
    double abs_x = fabs(x);
    bool is_negative = x < 0;

    while (abs_x > TWO_PI) {
        abs_x -= floor(abs_x / TWO_PI) * TWO_PI;
        if (abs_x <= PI_4)
            return sen(is_negative ? -abs_x : abs_x);
    }

    x = is_negative ? -abs_x : abs_x;

    if (x < 0) 
        x += TWO_PI;

    if (PI_4 < x && x <= THREE_PI_4)
        return _cos(x - PI_2);
    else if (THREE_PI_4 < x && x <= FIVE_PI_4)
        return -sen(x - M_PI);
    else if (FIVE_PI_4 < x && x <= SEVEN_PI_4)
        return -_cos(x - THREE_PI_2);
    else if (SEVEN_PI_4 < x && x <= TWO_PI)
        return sen(x - TWO_PI);
    else
        return sen(x);
}

double handle_cos_large_argument(double x) {
    double abs_x = fabs(x);
    bool is_negative = x < 0;

    while (abs_x > TWO_PI) {
        abs_x -= floor(abs_x / TWO_PI) * TWO_PI;
        if (abs_x <= PI_4)
            return cos(is_negative ? -abs_x : abs_x);
    }

    x = is_negative ? -abs_x : abs_x;

    if (x < 0) 
        x += TWO_PI;

    if (PI_4 < x && x <= THREE_PI_4)
        return -sen(x - PI_2);
    else if (THREE_PI_4 < x && x <= FIVE_PI_4)
        return -_cos(x - M_PI);
    else if (FIVE_PI_4 < x && x <= SEVEN_PI_4)
        return sen(x - THREE_PI_2);
    else if (SEVEN_PI_4 < x && x <= TWO_PI)
        return _cos(x - TWO_PI);
    else
        return _cos(x);
}

double sen(double x) {    
    if (fabs(x) > PI_4)
        return handle_sen_large_argument(x);
    else {
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
    if (fabs(x) > PI_4)
        return handle_cos_large_argument(x);
    else {    
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
}

double e(double x) {
    static const double E_K2 = 0.5; // 1.0 / 2.0
    static const double E_K3 = 0.16666666666666666; // 1.0 / 6.0
    static const double E_K4 = 0.041666666666666664; // 1.0 / 24.0
    
    static const double E_ARR[] = {1.0, 1.0, E_K2, E_K3, E_K4};
    static const int E_N = sizeof(E_ARR) / sizeof(E_ARR[0]);

    return horner(E_ARR, x, E_N);
}

double e_with_bailey_reduction(double x) {
    static const double E_K2 = 0.5; // 1.0 / 2.0
    static const double E_K3 = 0.16666666666666666; // 1.0 / 6.0
    static const double E_K4 = 0.041666666666666664; // 1.0 / 24.0ic 
    static const double ln2 = 0.69314718055994530942; 
    static const double ln2_2 = 1.3862943611198906188; // ln2 * 2

    static const double E_ARR[] = {1.0, 1.0, E_K2, E_K3, E_K4};
    static const int E_N = sizeof(E_ARR) / sizeof(E_ARR[0]);
    
    doubleIEEE temp = {x};
    temp.Dbits.E += 1;

    int n = ceil((temp.x - ln2)/ln2_2);
    double r = x - n * ln2;

    temp.x = r;
    temp.Dbits.E -= 8;
    r = temp.x;

    double result = horner(E_ARR, r, E_N);
    result = iterative_opt_pow(result, 256);

    temp.x = 2;
    temp.Dbits.E += n-1; 
    
    double multiplier = temp.x;

    return result * multiplier; //da pra ao invés de multiplier usar só o temp.x, mas talvez assim fica mais legível.
}                               //porém, é um double a mais.

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
