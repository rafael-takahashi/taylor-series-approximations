#include "elementary.h"

double sen(double x) {
    double y = x * x;
    double A, B, C, D;
  
    A = -1.0/6.0;
    B = 1.0/120.0;
    C = -1.0/5040.0;
    D = 1.0/362880.0;

    return x * (1 + y * (A + y * (B + y * (C + y * D))));
}