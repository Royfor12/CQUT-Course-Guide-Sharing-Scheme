#include <stdio.h>

int main() {
    long long product;
    for (int k = 1; k <= 35; k++) {
        product = 1;
        for (int i = 1; i <= k; i++) {
            product *= i;
        }
        printf("%d! = %d\n", k, product);
    }
    
return 0;
}