#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, delta;

    scanf("%lf %lf %lf", &a, &b, &c);
    delta = b * b - 4 * a * c;

    if (a != 0) {
        if (delta > 0) {
            double x1, x2;
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            if (x1 == -0.00) x1 = 0.00;
            if (x2 == -0.00) x2 = 0.00;
            printf("%.2lf\n%.2lf", x1, x2);
        } else if (delta == 0) {
            double x;
            x = -b / (2 * a);
            if (x == -0.00) x = 0.00;
            printf("%.2lf", x);
        } else {
            double x3, x4;
            x3 = -b / (2 * a);
            x4 = sqrt(-delta) / (2 * a);
            if (x3 == -0.00) x3 = 0.00;
            if (x4 == -0.00) x4 = 0.00;
            printf("%.2lf+%.2lfi\n%.2lf-%.2lfi", x3, x4, x3, x4);
        }
    } else if (b != 0) {
        double x0;
        x0 = -c / b;
        if (x0 == -0.00) x0 = 0.00;
        printf("%.2lf", x0);
    } else if (c != 0) {
        printf("Not An Equation");
    } else {
        printf("Zero Equation");
    }

    return 0;
}
