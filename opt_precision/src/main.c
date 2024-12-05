#include <stdio.h>
#include <math.h>
#include "elementary.h"

int main() {

    FILE *f = fopen("plot/data.txt", "w");

    if (f == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    double x, y;

    /*
    double limit = 2.0 * M_PI;    

    for (x = -limit; x <= limit; x += 0.1) {
        y = fabs(sen(x) - sin(x));
        fprintf(f, "%.15lf %.15lf\n", x, y);
    }
    */

    double limit_exponential = 30; 
    
    for (x = -limit_exponential; x <= limit_exponential; x += 0.1) {
        y = fabs(e_with_bailey_reduction(x) - exp(x));
        fprintf(f, "%.12lf %.12lf\n", x, y);
    }

    fclose(f);

    return 0;
}