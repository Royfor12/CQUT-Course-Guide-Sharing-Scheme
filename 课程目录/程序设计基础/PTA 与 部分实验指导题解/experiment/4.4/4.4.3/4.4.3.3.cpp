#include <stdio.h>

int main() {
    double product, e;
    for (int k = 1; k <= 6; k++) {
        product = 1;
        for (int i = 1; i <= k; i++) {
            product *= i;
        }
        e += 1.0 / product;
    }

    e += 1;
    printf("e = %f\n", e);

return 0;
}
