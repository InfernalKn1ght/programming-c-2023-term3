#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

double f(double x, ...) {
    va_list l;
    va_start(l, x);
    double sum = x;
    double i = va_arg(l, double);
    int j = 1;

    while (i != 0) {
        sum += i;
        i = va_arg(l, double);
        ++j;
    }

    return sum / j;
}

int main() {
    printf("%f", f(2.5, 4.0, 5.0 , 0.0));
    
    return EXIT_SUCCESS;
}