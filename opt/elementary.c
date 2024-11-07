#include "elementary.h"

static const double A = -0.16666666666666666;  // -1.0 / 6.0
static const double B = 0.008333333333333333;  // 1.0 / 120.0
static const double C = -0.0001984126984126984; // -1.0 / 5040.0
static const double D = 0.0000027557319223985893; // 1.0 / 362880.0

double sen(double x) {
    double y = x * x;
    return x * (1 + y * (A + y * (B + y * (C + y * D))));
}