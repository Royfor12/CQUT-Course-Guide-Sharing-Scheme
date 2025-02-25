#include <stdio.h>
#include <math.h>

int main() {
    float x, result;

    while (1) {
        printf("请输入一个浮点数 x (1.0 <= x <= 100.0): ");
        scanf("%f", &x);

        if (x >= 1.0 && x <= 100.0) {
            break; 
        } else {
            printf("输入的值不在 1.0 到 100.0 范围内，请重新输入。\n");
        }
    }

    result = pow(x, 5);

    printf("x 的五次方是: %.2f\n", result);

return 0;
}
