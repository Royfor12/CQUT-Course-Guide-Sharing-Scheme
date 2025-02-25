#include <stdio.h>

int main() {
    double result;
    for (int k = 2; k <= 7; k++) {
        result = (4 * k * k) / 2 * (k - 1) / 2 * (k + 1);
        result *= result;
    }
    printf("pi/2 = %lf\n", result);

return 0;
}
