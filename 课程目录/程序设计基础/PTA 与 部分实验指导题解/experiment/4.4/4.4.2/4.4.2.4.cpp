#include <stdio.h>
#include <math.h>

double taylor_sin(double x, int n) {
    double result = 0.0;
    for (int i = 0; i <= n; i++) {
        result += (pow(-1, i) * pow(x, 2 * i + 1)) / tgamma(2 * i + 2);
    }
    return result;
}

int main() {
    double x;
    scanf("%lf", &x);

    int n = 0;
    double error = 1.0;
    while (error > 1e-3) {
        n++;
        error = fabs(sin(x) - taylor_sin(x, n));
    }

    printf("sin(%.2f) = %.6f\n", x, taylor_sin(x, n));
    return 0;
}
