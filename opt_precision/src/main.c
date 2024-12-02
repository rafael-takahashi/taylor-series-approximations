#include <stdio.h>
#include <math.h>
#include "elementary.h"
#include "pow.h"

int main() {

    FILE *f = fopen("plot/data.txt", "w");

    if (f == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    double x, y;

    double max_x = M_PI / 4.0;    

    for (x = -max_x; x <= max_x; x += 0.1) {
        y = fabs(sen(x) - sin(x));
        fprintf(f, "%.10lf %.10lf\n", x, y); 
    }

    fclose(f);

    return 0;
}