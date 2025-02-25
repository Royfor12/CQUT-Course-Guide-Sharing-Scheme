#include <stdio.h>
#include <math.h>

int main() {
    double num, a = 0.0, b = 1.0, c = 0.0, d;
    
    for (int i = 1; i < 11; i++) {
        scanf("%lf", &num);
        a += num;
        b *= num;
        c += num * num;
    }

    d = a * a;

    printf("sum: %.2lf\n", a);
    printf("product: %.2lf\n", b);
    printf("sum of square: %.2lf\n", c);
    printf("square of sum: %.2lf\n", d);

return 0;
}
