#include <stdio.h>
#include <math.h>
#include "definitions.h"
#include "elementary.h"

int main() {

    FILE *f = fopen("plot/data.txt", "w");

    if (f == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    double x, y;

    double limit = 2.0 * TWO_PI;    

    for (x = -limit; x <= limit; x += 0.1) {
        y = fabs(sen(x) - sin(x));
        fprintf(f, "%.15lf %.15lf\n", x, y);
    }

    fclose(f);

    return 0;
}