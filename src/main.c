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

    double limit = TWO_PI;    

    for (x = -limit; x <= limit; x += 0.1) {
        y = fabs(sen(x) - sin(x));
        fprintf(f, "%.12lf %.12lf\n", x, y);
    }

    fclose(f);

    return 0;
}