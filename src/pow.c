#include <stdbool.h>
#include <math.h>
#include "pow.h"

double iterative_opt_pow(double x, long y) {
    if (x == 0 && y <= 0) return NAN;
    else if (x == 0 && y > 0) return 0;
    else if (x != 0 && y == 0) return 1;
    else if (y == 1) return x;
    else {
        bool is_negative = false;

        if (y < 0) {
            y = -y;
            is_negative = true;
        }

        double res = 1;

        /* 
            Exponentation by Squaring Algorithm : https://www.youtube.com/watch?app=desktop&v=bRMVU3Gy_JY.
            Binary representations provides which powers of x must be multiplied with the final result.
            Example: take y = 13. In order to calculate x^13, consider that d13 = b1101.
            b1101 tells us exactly which bases need to be considered in the final result, since
            13 = 1*2^3 + 1*2^2 + 0*2^1 + 1*2^0 = 8 + 4 + 1, we must multiply the final result by 
            x^8, x^4 and x^1.
            An easy way to do that is by using a loop that iterates through the exponent y and checks if
            current bit is 1. If it is, then consider current base in the final answer.
        */
        while (y > 1) {
            if (y & 1) {
                res *= x;
            }
            x *= x;
            y >>= 1;
        }
        res *= x;

        return is_negative ? 1 / res : res;
    }
}
