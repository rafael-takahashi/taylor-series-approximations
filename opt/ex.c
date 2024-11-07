#include "ex.h"

static const double k2 = 0.5; // 1.0 / 2.0
static const double k3 = 0.16666666666666666; // 1.0 / 6.0
static const double k4 = 0.041666666666666664; // 1.0 / 24.0

double ex(double x) {
    return 1 + x * (1 + x * (k2 + x * (k3 + x * k4)));
}